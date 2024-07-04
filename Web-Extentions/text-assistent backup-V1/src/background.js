
const init = async () => {
    const existingContexts = await chrome.runtime.getContexts({});
    let recording = false;

    const offscreenDocument = existingContexts.find(
        (c) => c.contextType === 'OFFSCREEN_DOCUMENT'
    )

    if (!offscreenDocument) {
        // Create an offscreen document.
        await chrome.offscreen.createDocument({
            url: 'offscreen.html',
            reasons: ['USER_MEDIA'],
            justification: 'Recording from chrome.tabCapture API'
        });
    } else {
        recording = offscreenDocument.documentUrl.endsWith('#recording');
    }
}



const startAssistent = async () => {
    chrome.storage.local.set({ isActive: true }, () => {
        console.log('Extension active status set to true');
    });
    init();
    chrome.tabs.query({ active: true, currentWindow: true }, async (tabs) => {
        if (tabs.length > 0) {
            const tabId = tabs[0].id;

            // Get media stream ID for the tab
            const streamID = await chrome.tabCapture.getMediaStreamId({
                targetTabId: tabId
            });

            // Send message to start recording
            chrome.runtime.sendMessage({
                type: 'start-recording',
                target: 'offscreen',
                data: streamID
            });
        } else {
            console.error('No active tab found');
        }
    });
};

const stopAssistent = () => {
    chrome.storage.local.set({ isActive: false }, () => {
        console.log('Extension active status set to false');
    });
    init();

    chrome.runtime.sendMessage({
        type: 'stop-recording',
        target: 'offscreen'
    });
};

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
    switch (message.type) {
        case "startAssistent":
            console.log("background.js -> activating assistant");
            startAssistent();
            sendResponse({ status: "Assistant started" });
            break;
        case "stopAssistent":
            console.log("background.js -> stopping assistant");
            stopAssistent();
            sendResponse({ status: "Assistant stopped" });
            break;
        default:
            console.log("background.js -> unknown message type");
            sendResponse({ status: "Unknown message type" });
    }

    // Return true to indicate you want to send a response asynchronously
    return true;
});

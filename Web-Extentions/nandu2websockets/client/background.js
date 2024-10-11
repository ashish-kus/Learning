let ws = new WebSocket('ws://localhost:8080');

ws.onopen = () => {
    console.log('Connected to WebSocket server');
};

ws.onmessage = event => {
    console.log(`Message from server: ${event.data}`);
    chrome.tabs.query({ active: true, currentWindow: true }, tabs => {
        if (tabs.length > 0) {
            chrome.tabs.sendMessage(tabs[0].id, { type: 'colorMessage', color: event.data });
        }
        ws.onmessage = event => {
            console.log(`Message from server: ${event.data}`);
            chrome.tabs.query({ active: true, currentWindow: true }, tabs => {
                if (tabs.length > 0) {
                    chrome.tabs.sendMessage(tabs[0].id, { type: 'colorMessage', color: event.data });
                }
            });
        };
        
    });
};

ws.onclose = () => {
    console.log('Disconnected from WebSocket server');
};

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
    if (message.type === 'sendMessage') {
        ws.send(message.color);
        sendResponse({ status: 'sent' });
    }
});

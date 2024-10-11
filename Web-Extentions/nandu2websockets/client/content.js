window.onload = function() {
    console.log('Content script loaded');
    let bubble = document.createElement('div');
    bubble.id = 'color-bubble';
    bubble.style.width = '50px';
    bubble.style.height = '50px';
    bubble.style.borderRadius = '50%';
    bubble.style.position = 'fixed';
    bubble.style.bottom = '10px';
    bubble.style.right = '10px';
    bubble.style.backgroundColor = 'gray';
    document.body.appendChild(bubble);
};

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
    if (message.type === 'colorMessage') {
        const bubble = document.getElementById('color-bubble');
        if (bubble) {
            bubble.style.backgroundColor = message.color;
        }
        sendResponse({ status: 'color changed' });
    }
});

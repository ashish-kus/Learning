document.getElementById('send-red').addEventListener('click', () => {
    sendMessageToBackground('red');
});

document.getElementById('send-green').addEventListener('click', () => {
    sendMessageToBackground('green');
});

document.getElementById('send-blue').addEventListener('click', () => {
    sendMessageToBackground('blue');
});

function sendMessageToBackground(color) {
    chrome.runtime.sendMessage({ type: 'sendMessage', color: color }, response => {
        if (chrome.runtime.lastError) {
            console.error(chrome.runtime.lastError.message);
        } else if (response && response.status) {
            console.log(response.status);
        } else {
            console.error('No response received');
        }
    });
}

// content.js
const button = document.createElement('div');
button.id = 'siri-button';
button.style.position = 'fixed';
button.style.bottom = '20px';
button.style.right = '20px';
button.style.width = '50px';
button.style.height = '50px';
button.style.borderRadius = '50%';
button.style.backgroundColor = '#007AFF';
button.style.display = 'flex';
button.style.alignItems = 'center';
button.style.justifyContent = 'center';
button.style.cursor = 'pointer';
button.style.zIndex = '1000';
button.innerHTML = '<img src="' + chrome.runtime.getURL('microphone-icon.png') + '" alt="Mic" style="width: 24px; height: 24px;">';

document.body.appendChild(button);

button.addEventListener('click', () => {
  chrome.runtime.sendMessage({ action: 'toggleRecording' });
});

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  if (message.action === 'updateUI') {
    const { data } = message;
    button.style.backgroundColor = data.color; // Change button color based on response
    button.title = data.text; // Show response text on hover
  }
});

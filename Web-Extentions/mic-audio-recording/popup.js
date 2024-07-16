document.getElementById('start').addEventListener('click', () => {
  chrome.runtime.sendMessage({ type: 'start-recording' });
});

document.getElementById('stop').addEventListener('click', () => {
  chrome.runtime.sendMessage({ type: 'stop-recording' });
});

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  if (message.type === 'audio-data') {
    const audioBlob = new Blob(message.data, { type: 'audio/webm' });
    const audioUrl = URL.createObjectURL(audioBlob);
    const audioPlayback = document.getElementById('audioPlayback');
    audioPlayback.src = audioUrl;
  }
});

chrome.storage.local.get('audioUrl', (result) => {
  if (result.audioUrl) {
    const audioPlayback = document.getElementById('audioPlayback');
    audioPlayback.src = result.audioUrl;
  }
});


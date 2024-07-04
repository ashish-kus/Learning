let isRecording = false;
let mediaRecorder;
let audioChunks = [];

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  if (message.action === 'toggleRecording') {
    if (!isRecording) {
      startRecording();
    } else {
      stopRecording();
    }
  }
});

function startRecording() {
  isRecording = true;
  navigator.mediaDevices.getUserMedia({ audio: true }).then(stream => {
    mediaRecorder = new MediaRecorder(stream);
    mediaRecorder.ondataavailable = event => {
      audioChunks.push(event.data);
    };
    mediaRecorder.onstop = () => {
      const audioBlob = new Blob(audioChunks, { type: 'audio/wav' });
      audioChunks = [];
      sendAudioToApi(audioBlob);
    };
    mediaRecorder.start();
  }).catch(error => {
    console.error('Error accessing microphone:', error);
  });
}

function stopRecording() {
  isRecording = false;
  mediaRecorder.stop();
}

function sendAudioToApi(audioBlob) {
  const formData = new FormData();
  formData.append('audio', audioBlob);

  fetch('YOUR_API_ENDPOINT', {
    method: 'POST',
    body: formData
  })
  .then(response => response.json())
  .then(data => {
    chrome.tabs.query({ active: true, currentWindow: true }, tabs => {
      chrome.tabs.sendMessage(tabs[0].id, { action: 'updateUI', data });
    });
  })
  .catch(error => console.error('Error sending audio to API:', error));
}

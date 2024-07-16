document.getElementById('start').addEventListener('click', requestMicrophonePermission);
document.getElementById('stop').addEventListener('click', stopRecording);

let mediaRecorder;
let recordedChunks = [];

function requestMicrophonePermission() {
  chrome.permissions.request({
    permissions: ['microphone']
  }, (granted) => {
    if (granted) {
      startRecording();
    } else {
      console.error('Microphone permission not granted');
    }
  });
}

async function startRecording() {
  try {
    const stream = await navigator.mediaDevices.getUserMedia({ audio: true });
    mediaRecorder = new MediaRecorder(stream);

    mediaRecorder.ondataavailable = function(event) {
      if (event.data.size > 0) {
        recordedChunks.push(event.data);
      }
    };

    mediaRecorder.onstop = function() {
      const audioBlob = new Blob(recordedChunks, { type: 'audio/webm' });
      const audioUrl = URL.createObjectURL(audioBlob);
      const audioPlayback = document.getElementById('audioPlayback');
      audioPlayback.src = audioUrl;
      recordedChunks = [];
    };

    mediaRecorder.start();
  } catch (err) {
    if (err.name === 'NotAllowedError') {
      console.error('Microphone access denied by the user.');
    } else if (err.name === 'NotFoundError') {
      console.error('No microphone device found.');
    } else if (err.name === 'NotReadableError') {
      console.error('Microphone is already in use.');
    } else {
      console.error('Error accessing microphone:', err.name, err.message);
    }
  }
}

function stopRecording() {
  if (mediaRecorder && mediaRecorder.state !== 'inactive') {
    mediaRecorder.stop();
  }
}

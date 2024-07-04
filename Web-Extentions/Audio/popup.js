document.addEventListener('DOMContentLoaded', function () {
  const recordButton = document.getElementById('recordButton');
  let mediaRecorder;
  let chunks = [];

  recordButton.addEventListener('click', async () => {
    if (mediaRecorder && mediaRecorder.state === 'recording') {
      mediaRecorder.stop();
      recordButton.textContent = 'Record';
    } else {
      try {
        const stream = await navigator.mediaDevices.getUserMedia({ audio: true });
        mediaRecorder = new MediaRecorder(stream);

        mediaRecorder.ondataavailable = (event) => {
          if (event.data.size > 0) {
            chunks.push(event.data);
          }
        };

        mediaRecorder.onstop = () => {
          if (chunks.length > 0) {
            const blob = new Blob(chunks, { type: 'audio/wav' });
            const url = URL.createObjectURL(blob);
            const audio = new Audio(url);
            audio.controls = true;
            document.body.appendChild(audio);
          } else {
            alert('No audio data recorded.');
          }
        };

        mediaRecorder.start();
        recordButton.textContent = 'Stop';
      } catch (error) {
        console.error('Error accessing microphone:', error);
        if (error.name === 'NotAllowedError') {
          alert('Microphone access was denied. Please enable microphone permissions.');
        } else if (error.name === 'NotFoundError' || error.name === 'SecurityError') {
          alert('Microphone access is not available. Please check your browser settings.');
        } else {
          alert('Error accessing microphone. Please check your browser settings.');
        }
      }
    }
  });
});


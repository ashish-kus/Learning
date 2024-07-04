console.log("hello --> login2.js");

const Lform = document.getElementById('login-button');
console.log(Lform);

Lform.addEventListener('click', () => {
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;

    console.log(username, password);
    // Replace with actual authentication logic
    if (username && password) {
        chrome.storage.sync.set({ loggedIn: true }, () => {
            console.log('User is now logged in.');
            window.location.href = 'popup.html'; // Redirect to popup or main page
        });
        chrome.storage.sync.get(['loggedIn'],(result)=>{
            console.log(result)
        });
    } else {
        alert('Please enter both username and password.');
    }
});

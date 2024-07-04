console.log("Hello --> popup.js");
const assistentBtn = document.querySelector("#AssistBtn");

if (assistentBtn) {
    // Check if the user is logged in
    chrome.storage.sync.get(['loggedIn'], (result) => {
        console.log(result); // Log the result object to see its content
        if (!result.loggedIn) {
            window.location.href = './login.html';
        } else {
            console.log('User is logged in.');
        }
    });

    // Check if assistant is active
    chrome.storage.local.get('isActive', (result) => {
        if (result.isActive) {
            // If active, set border-color to red
            assistentBtn.style.borderColor = 'red';
        } else {
            // If not active, reset border-color to default
            assistentBtn.style.borderColor = ''; // Removes inline style
        }
    });

    // Function to inject content.js into the active tab
    const injectBubble = async () => {
        try {
            const tabs = await chrome.tabs.query({ active: true, currentWindow: true });
            if (!tabs || tabs.length === 0) return;

            const tabId = tabs[0].id;
            console.log("popup.js --> inject into tab", tabId);
            await chrome.scripting.executeScript({
                // content.js is the file that will be injected
                files: ["content.js"],
                target: { tabId },
            });
            assistentBtn.style.border = '2px solid red'; // This will set a red border around the button
        } catch (error) {
            console.error("Failed to inject content.js:", error);
        }
    };

    // Function to remove bubble
    const removeBubble = async () => {
        try {
            const tabs = await chrome.tabs.query({ active: true, currentWindow: true });
            if (!tabs || tabs.length === 0) return;

            const tabId = tabs[0].id;
            console.log("popup.js --> removing Hiremate-Bubble", tabId);
            await chrome.scripting.executeScript({
                target: { tabId },
                function: () => {
                    const hiremateBubble = document.querySelector("#Hiremate-bubble");
                    if (hiremateBubble) {
                        hiremateBubble.remove();
                    }
                },
            });
        } catch (error) {
            console.error("Failed to remove Hiremate-Bubble:", error);
        }
    };

    const activateAssistant = () => {
        console.log("popup.js --> Activating Assistant");

        chrome.runtime.sendMessage({ type: 'startAssistent' }, (response) => {
            console.log(response.status);
            assistentBtn.style.borderColor = 'red';
        });
        injectBubble();
    };

    const de_activateAssistant = () => {
        console.log("popup.js --> De_Activating Assistant");

        assistentBtn.style.borderColor = '';
        chrome.runtime.sendMessage({ type: 'stopAssistent' }, (response) => {
            console.log(response.status);
        })
        removeBubble();
    };

    const toggleAssistent = () => {
        chrome.storage.local.get('isActive', (result) => {
            if (result.isActive) {
                de_activateAssistant();
            } else {
                activateAssistant();
            }
        });
    };

    // Add event listener to the assistant button
    assistentBtn.addEventListener("click", () => {
        console.log("popup.js --> clicked assistant btn");
        toggleAssistent();
    });
} else {
    console.error('AssistBtn element not found');
}

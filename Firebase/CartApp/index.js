import { initializeApp } from "https://www.gstatic.com/firebasejs/9.15.0/firebase-app.js";
import { getDatabase, ref, push, onValue, remove } from "https://www.gstatic.com/firebasejs/9.15.0/firebase-database.js";

const appSettings = {
  databaseURL: "https://playground-1758c-default-rtdb.asia-southeast1.firebasedatabase.app/"
}

const app = initializeApp(appSettings);
const database = getDatabase(app);
const shoppingListDB = ref(database, "shoppingList")
const inputFieldEl = document.getElementById("input-field");
const addButtonEL = document.getElementById("add-button");
const shoppingListEL = document.getElementById("shopping-list");

addButtonEL.addEventListener("click", function() {
  let inputValue = inputFieldEl.value
  push(shoppingListDB, inputValue)
  clearInputField();
})

onValue(shoppingListDB, function(snapshot) {

  if (snapshot.exists()) {
    let itemArray = Object.entries(snapshot.val());
    clearShoppingListEl();
    for (let i = 0; i < itemArray.length; i++) {
      let currentItem = itemArray[i];
      appendItemToShoppingListEl(currentItem);
    }
  }else {
    shoppingListEL.innerHTML = "No Item in the list";
  }
})

function clearShoppingListEl() {
  shoppingListEL.innerHTML = "";
}
function clearInputField() {
  inputFieldEl.value = ""
}

function appendItemToShoppingListEl(item) {
  let itemID = item[0];
  let itemValue = item[1];

  let newEl = document.createElement("li");
  newEl.textContent = itemValue;

  newEl.addEventListener("dblclick", function() {
    let locationOfItemInDB = ref(database, `shoppingList/${itemID}`)
    remove(locationOfItemInDB);
  })
  shoppingListEL.append(newEl);
}


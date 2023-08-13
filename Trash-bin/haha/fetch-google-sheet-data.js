const sheetId = "WqO7lLF5UG76WAOozAQ-Y61dcjvB528_1vx4m_yJUAk";
const spreadsheetUrl = "https://docs.google.com/spreadsheets/d/" + sheetId;

const xhr = new XMLHttpRequest();
xhr.open("GET", spreadsheetUrl);
xhr.onload = function() {
  if (xhr.status === 200) {
    const data = JSON.parse(xhr.responseText);
    console.log(data);
  } else {
    console.log("Error fetching data: " + xhr.status);
  }
};

xhr.send();



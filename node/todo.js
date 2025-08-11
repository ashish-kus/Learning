const express = require("express");
const app = express();
app.use(express.json());

let todos = [];
let nextId = 1;

app.get("/", (req, res) => {
  res.send("TODO is Live");
});

app.get("/todos", (req, res) => {
  res.json(todos);
});

app.post("/todos", (req, res) => {
  const { task } = req.body;
  if (!task) {
    return res.status(400).json({ error: "TASK NOT FOUND" });
  }
  const newTodo = { id: nextId++, task };
  todos.push(newTodo);
  res.status(201).json({ newTodo });
});

app.put("/todos/:id", (req, res) => {
  const id = parseInt(req.params.id);
  const { task } = req.body;

  const todo = todos.find((t) => t.id === id);
  if (!todo) return res.status(404).json({ error: "Todo not found" });

  todo.task = task;
  res.json(todo);
});

app.delete("/todos", (req, res) => {
  res.json(todos);
});

app.listen(3000, () => {
  console.log("Server is running on http://localhost:3000");
});

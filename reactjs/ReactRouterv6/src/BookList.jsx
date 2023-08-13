import React from "react"
import { Link } from 'react-router-dom'


function booklist() {
  return (
    <>
      <h1>Booklist</h1>
      <Link to="/books/1">BOOK1</Link>
      <br />
      <Link to="/books/2">BOOK2</Link>
      <br />
      <Link to="/books/new">NewBook</Link>
      <br />
    </>
  )
}

export default booklist;

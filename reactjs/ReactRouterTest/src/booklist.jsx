import React from "react";
import { Link } from "react-router-dom";

export function BookList(){
  return (
  <>
    <h1>BookList</h1>
    <Link to="/books/1"> BOOK 1</Link>
    <Link to="/books/2"> BOOK 2</Link>
  </>
  )
}

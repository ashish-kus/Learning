import React from "react"
import { useParams } from "react-router-dom";
function book() {
  const { id } = useParams()
  return (
  <>
      <h2>books {id}</h2>
  </>
  )
}

export default book;

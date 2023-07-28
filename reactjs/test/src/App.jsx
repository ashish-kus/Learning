import { useState, useEffect } from 'react'
import './App.css'


const Person = (props) => {
  return (
  <>
    <h1>Name : {props.name}</h1>
    <h2>Last name: {props.lastname}</h2>
    <h3>Age: {props.age}</h3>
  </>
  )
}


const App = () =>  {
  const [counter, setCounter] = useState(0);

  useEffect(()=> {
    alert("reload");
  },[]);


  return (
    <div className='App'>
      <button onClick={() => setCounter((prevCount) => prevCount - 1  )}> - </button>
      <h1>{counter}</h1>
      <button onClick={() => setCounter((prevCount) => prevCount + 1  )}> + </button>
    </div>
  )
}

export default App

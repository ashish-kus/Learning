import React from 'react';
import { Link, Route, Routes } from 'react-router-dom';
import Home from './home';
import Books from './books';

function App() {
  return (
  <>
      <nav>
        <ul>
          <li><Link to='/'>HOME</Link></li>
          <li><Link to='/books'>books</Link></li>
        </ul>
      </nav>
      <Routes>
        <Route path='/' element={<Home />} />
        <Route path='/books' element={<Books />} />
      </Routes>
  </>
  )
}
export default App 

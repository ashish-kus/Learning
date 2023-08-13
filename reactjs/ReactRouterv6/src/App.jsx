import { Link, Route, Routes } from 'react-router-dom'
import Home from './Home';
import BookList from './BookList';
import Book from './Book';
import NewBook from './NewBook';
import NotFound from './NotFound.jsx';

function App() {
  return (
    <>
    <nav>
      <ul>
        <li><Link to="/">Home</Link></li>
        <li><Link to="/books">books</Link></li>
      </ul>
    </nav>

    <Routes>
        <Route path='/' element={ <Home/> } />
        <Route path='/books' >
          <Route index element={ <BookList/> } />
          <Route path=':id'  element={ <Book /> } />
          <Route path='new' element={ <NewBook/> } />
        </Route>
        <Route path='*' element={ <NotFound /> } />
    </Routes>
    
    </>
  )
}

export default App


 //     <Routes>
 //      <Route path='/' element={ <Home /> } />
 //      <Route path='/books' element={ <BookList /> } />
 //      <Route path='/books/:id' element={ <Book /> } />
 //      <Route path='/books/new' element={ <NewBook /> } />
 //      <Route path='*' element={ <NotFound /> } />
 //    </Routes>
 // 

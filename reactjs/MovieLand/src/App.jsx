import React from 'react';
import {useState, useEffect } from 'react';
import './App.css'; 
import SearchIcon from './search.svg';
import MovieCard from './common/MovieCard';
// b2adf34c
//

const API_URL = "http://www.omdbapi.com?apikey=b2adf34c" 


const App = () => {
  const [movies, setMovies] = useState([]);
  const [SearchTerm, setSearchTerm] = useState("");
  const searchMovie = async (title) => {
  const response = await  fetch(`${API_URL}&s=${title}`);
  const data = await response.json();
  console.log(data);
  setMovies(data.search);
  }
  
  useEffect(()=> {
    searchMovie('spiderman');
  })
  return (
    <div className ="app">
      <h1>MovieLand</h1>
      <div className='search'>
        <input 
          type="text" name="search"
          value={SearchTerm}
          onChange={(e) =>  setSearchTerm(e.target.value)}
        />
        <img
          src={SearchIcon} alt="search"
          onChange={() => searchMovie(SearchTerm)}
        />
      </div>
      
      {
        movies?.leangth > 0 
        ? (
          <div className='container'>
              {movies.map((movie) => (
                 <MovieCard movie={movie} />
                ))}
          </div>
        ):(
          <div className='empty'>
              <h2>No Movies Found </h2>
          </div>
        )
      }
    </div>
  )
}

export default App

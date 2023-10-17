import './App.css'
const App = () => {
  return (
    <section className='booklist'>
      
      <Book/>
      <Book/>
      <Book/>
      <Book/>
      <Book/>
      <Book/>
      <Book/>
      <Book/>
    </section>
  )
}

const Book = () => {
  return (
  <section className='book'>
      <Tittle/>
      <Auther/>
      <Image/>
    </section>
  )
}

const Image = () => {
  return (
  <>
    <img src="https://wimpykid.com/wp-content/uploads/2021/10/1-300x500.png" />
  </>
  )
}

const Tittle = () => {
  return (
  <>
    <h1>Image place holder</h1>
  </>
  )
}

const Auther = () => {
  return (
  <>
    <h4>Image place holder</h4>
  </>
  )
}

export default App

import './App.css'
const books = [
  {
    author: 'Jordan Moore',
    id: 123,
    title: 'Interesting Facts For Curious Minds',
    img: 'https://images-na.ssl-images-amazon.com/images/I/81wgcld4wxL._AC_UL900_SR900,600_.jpg',
  },
  {
    author: 'James Clear',
    id: 124,
    title: 'Atomic Habits',
    img: 'https://images-na.ssl-images-amazon.com/images/I/81wgcld4wxL._AC_UL900_SR900,600_.jpg',
  },
];


// const ExampleEvent = () => {
//   const handleFormInput = () => {
//     console.log("input handeller");
//   };
//   const handelebtn = () => {
//     console.log("btn click");
//   }
//   return (
//     <section>
//       <form onSubmit={handleSubmit}>
//         <h2>Basic Form</h2>
//         <input type="txt" name="name" value="Name" onChange={handleFormInput} />
//         <button type="button" onClick={handelebtn}>BTN</button>
//       </form>
//     </section>
//   )
// }
const App = () => {
  const getBook = (id) => {
    const book = books.find((book) => book.id === id);
    console.log(book);
  };

  return (
    <section className='booklist'>
      {books.map((book) => {
        return <Book {...book} key={book.id} getBook={getBook} />;
      })}
    </section>
  );
};
const Book = (props) => {
  const { img, title, author, getBook } = props;
  console.log(props)
  return (
    <section className='book'>
      <img src={img} alt={title} />
      <h2>{title}</h2>
      <button  onClick={getBook}>click me</button>
      <h4>{author} </h4>
    </section>
  )
}
export default App

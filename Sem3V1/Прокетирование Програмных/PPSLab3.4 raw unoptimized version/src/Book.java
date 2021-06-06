public class Book {
    private Author author;
    private String name;
    private String genre;
    private String publicationDate;

    @Override
    public String toString() {
        return genre + " " + name + " " + author + " " + publicationDate;
    }

    public boolean initialize(String[] array) {
        if (array.length == 4) {
            this.name = array[0];
            author = new Author();
            this.author.initialize(array[1]);
            this.genre = array[2];
            try {
                Integer.parseInt(array[3]);
            } catch (NumberFormatException e) {
                System.out.println("Publication date error");
                return false;
            }
            this.publicationDate = array[3];
            return true;
        }
        System.out.println("Wrong filling of books");
        return false;
    }

    public Author getAuthor() {
        return author;
    }

    public int getDate() {
        return Integer.parseInt(this.publicationDate);
    }

    public String getGenre() {
        return this.genre;
    }
}
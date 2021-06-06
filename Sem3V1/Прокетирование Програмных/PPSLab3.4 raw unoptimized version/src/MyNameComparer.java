import java.util.Comparator;

public class MyNameComparer implements Comparator<Book>
{
    @Override
    public int compare(Book firstBook, Book secondBook)
    {
        return firstBook.getAuthor().getAsString().compareToIgnoreCase(secondBook.getAuthor().getAsString());
    }
}

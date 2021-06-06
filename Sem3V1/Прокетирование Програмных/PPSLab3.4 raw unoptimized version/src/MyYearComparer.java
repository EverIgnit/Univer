import java.util.Comparator;

public class MyYearComparer implements Comparator<Book>
{
    @Override
    public int compare(Book firstBook, Book secondBook)
    {
        return firstBook.getDate()-secondBook.getDate();
    }
}

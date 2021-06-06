import java.util.*;

public class Runner {
    private static TreeMap<Author, ArrayList<Book>> bookMap;
    private static TreeMap<String, ArrayList<Book>> genreMap;
    private static String name;
    private static String line;

    public static void main(String[] args) {
        bookMap = new TreeMap<Author, ArrayList<Book>>();
        genreMap = new TreeMap<String, ArrayList<Book>>();
        name = "file.csv";
        switch (args[0]) {
            case "file": {
                if (fromFileInitializing()) {
                    byYearSorting();
                    for (Author author : bookMap.keySet()) {
                        System.out.println("Author: " + author);
                        System.out.println(bookMap.get(author));
                    }
                    byNameSorting();
                    for (String genre : genreMap.keySet()) {
                        System.out.println("Genre: " + genre);
                        System.out.println(genreMap.get(genre));
                    }
                    break;
                }
            }
            default: {
                if (fromConsoleInitializing()) {
                    byYearSorting();
                    for (Author author : bookMap.keySet()) {
                        System.out.println("Author: " + author);
                        System.out.println(bookMap.get(author));
                    }
                    byNameSorting();
                    for (String genre : genreMap.keySet()) {
                        System.out.println("Genre: " + genre);
                        System.out.println(genreMap.get(genre));
                    }
                }
                break;
            }
        }
    }

    private static boolean fromFileInitializing() {
        Book book;
        String genre;
        ArrayList<Book> books;
        boolean defined = false;
        boolean gdefined;
        com.job4.Reader reader = new com.job4.Reader(name);
        if (!reader.isValid()) {
            System.out.println("Input-data file error!");
            return false;
        }
        while ((line = reader.read()) != null) {
            book = new Book();
            if (book.initialize(line.split(";"))) {
                genre = book.getGenre();
                defined = false;
                gdefined = false;
                Collection<Author> collection = bookMap.keySet();
                for (Author key : collection) {
                    if (key != null && ((Author) key).equals(book.getAuthor())) {
                        ((List<Book>) bookMap.get(key)).add(book);
                        defined = true;
                    }
                }
                if (!defined) {
                    books = new ArrayList<Book>();
                    books.add(book);
                    bookMap.put(book.getAuthor(), books);
                }
                /**************************************************/
                Collection<String> gcollection = genreMap.keySet();
                for (String key : gcollection) {
                    if (key != null && ((String) key).equals(genre)) {
                        ((List<Book>) genreMap.get(key)).add(book);
                        gdefined = true;
                    }
                }
                if (!gdefined) {
                    books = new ArrayList<Book>();
                    books.add(book);
                    genreMap.put(book.getGenre(), books);
                }
                /***************************************************/
            } else {
                return false;
            }
        }
        return true;
    }

    private static boolean fromConsoleInitializing() {
        @SuppressWarnings("resource")
        Scanner scanner = new Scanner(System.in);
        com.job4.Scanning scanning = new com.job4.Scanning();
        String[] array = new String[4];
        boolean exit = false;
        while (!exit) {
            System.out.println("1)->> To enter data about the book");
            System.out.println("0)->> Exit and show books");
            if (scanner.hasNextInt()) {
                switch (scanner.nextInt()) {
                    case 1: {
                        System.out.println("Enter the genre");
                        array[2] = scanner.next();
                        System.out.println("Enter the title");
                        array[0] = scanning.getInputString();
                        System.out.println("Enter the Author");
                        array[1] = scanning.getInputString();
                        System.out.println("Enter the publicatiob date");
                        array[3] = scanner.next();
                        try {
                            Integer.parseInt(array[3]);
                        } catch (NumberFormatException e) {
                            System.out.println("Publication date error");
                            break;
                        }

                        /******************************************************/
                        Book book;
                        String genre;
                        ArrayList<Book> books;
                        boolean defined = false;
                        boolean gdefined;
                        book = new Book();
                        if (book.initialize(array)) {
                            genre = book.getGenre();
                            defined = false;
                            gdefined = false;
                            Collection<Author> collection = bookMap.keySet();
                            for (Author key : collection) {
                                if (key != null && ((Author) key).equals(book.getAuthor())) {
                                    ((List<Book>) bookMap.get(key)).add(book);
                                    defined = true;
                                }
                            }
                            if (!defined) {
                                books = new ArrayList<Book>();
                                books.add(book);
                                bookMap.put(book.getAuthor(), books);
                            }
                            /**************************************************/
                            Collection<String> gcollection = genreMap.keySet();
                            for (String key : gcollection) {
                                if (key != null && ((String) key).equals(genre)) {
                                    ((List<Book>) genreMap.get(key)).add(book);
                                    gdefined = true;
                                }
                            }
                            if (!gdefined) {
                                books = new ArrayList<Book>();
                                books.add(book);
                                genreMap.put(book.getGenre(), books);
                            }
                            /***************************************************/
                            /**************************************************/
                        }
                        break;
                    }
                    case 0: {
                        exit = true;
                        break;
                    }
                    default: {
                        break;
                    }
                }
            } else {
                scanner.next();
            }
            System.out.println("*****************************************************************");
        }
        return true;
    }

    private static boolean byYearSorting() {
        Collection<Author> collection = bookMap.keySet();
        for (Author key : collection) {
            if (key != null) {
                Collections.sort(bookMap.get(key), new MyYearComparer());
                ;
            }
        }
        return true;
    }

    private static boolean byNameSorting() {
        Collection<String> collection = genreMap.keySet();
        for (String key : collection) {
            if (key != null) {
                Collections.sort(genreMap.get(key), new MyNameComparer());
            }
        }
        return true;
    }
}
public class Author implements Comparable<Author> {
    private String name;
    private String surname;
    private String patronymic;

    @Override
    public String toString() {
        return surname + " " + name + " " + patronymic;
    }

    public boolean initialize(String string) {
        StringBuffer buffer = new StringBuffer(string);
        try {
            this.surname = buffer.substring(0, buffer.indexOf(" "));
            this.name = buffer.substring(buffer.indexOf(" ") + 1, buffer.indexOf(" ") + 3);
            this.patronymic = buffer.substring(buffer.indexOf(" ") + 3, buffer.indexOf(" ") + 5);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Author initial error");
            return false;
        }
        return false;
    }

    public boolean equals(Author author) {
        if (author.toString().equals(this.toString())) {
            return true;
        }
        return false;
    }

    public String getAsString() {
        return surname + name + patronymic;
    }

    @Override
    public int compareTo(Author author) {
        return this.getAsString().compareTo(author.getAsString());
    }
}
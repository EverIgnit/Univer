import java.util.Scanner;
public class Collections{
    private String filePath="C:\Users\\1801080061\Downloads\PPSLab3\src\File2.txt";
    public static void main(String args[]){
        if (args[0]=="console"){

        }
        else{

        }

    }
}
class Book{
    private String name;
    private String author;
    private String ganre;
    private byte yearOfPublication;
}

class SideClass {
    private Set<Book> setList;
    public SideClass() {
        this.setList = new HashSet<>();
    }

    public void readDataFromFile(String path) {
        try
        {
            Reader reader = new FileReader(path);
            BufferedReader bufferedReader = new BufferedReader(reader);
            ArrayList<String> rawLineArray = new ArrayList<>();

            String line = "";

            while ((line = bufferedReader.readLine()) != null)
            {
                rawLineArray.add(line);
            }

            for (int i = 0; i < rawLineArray.size(); i++)
            {
                String[] buffer = rawLineArray.get(i).split(";");
                Set<Integer> bufferMap = new HashSet<>();

                for(int j = 0; j < buffer.length; j++)
                {
                    System.out.print(Integer.parseInt(buffer[j]) + " ");
                    bufferMap.add(Integer.parseInt(buffer[j]));
                }

                System.out.println();

                setList.add(bufferMap);
            }
        }
        catch (FileNotFoundException e)
        {
            System.out.println("Файл не найден, " + e);
        }
        catch (IOException e)
        {
            System.out.println("Ошибка ввода-вывода, " + e);
        }
    }

    public void readDataFromKeyBoard() {
        Scanner scanner = new Scanner(System.in);
        while (true)
        {
            Set<Book> set = new HashSet<>();

            String bufferString = "";
            System.out.println("Введите множество (целые числа через пробел): ");
            bufferString = scanner.nextLine();

            String[] splitArray = bufferString.split(" ");
            for (int i = 0; i < splitArray.length; i++)
                set.add(Integer.parseInt(splitArray[i]));

            setList.add(set);
            System.out.println("Ввести еще множество? (y/n)");
            bufferString = scanner.nextLine();
            if (bufferString.equals("n"))
                break;
        }
    }

    public HashSet<Integer> findMaUnionSet() {
        HashSet<Integer> maxUnionSet = null;
        if(setList.size()==1||setList.size()==0 )
        {
            HashSet<Integer> Error= new HashSet<>();
            for (Set<Integer> firstitem : setList)
                Error.addAll(firstitem);
            return Error;
        }
        Set<Integer> one = null,two = null;
        for (Set<Integer> firstitem : setList)
            for (Set<Integer> secondItem : setList)
                if (maxUnionSet != null)
                {
                    HashSet<Integer> tempSet = unity(firstitem, secondItem);
                    if (tempSet.size() > maxUnionSet.size()&&firstitem!=secondItem)
                    {
                        maxUnionSet = tempSet;
                        one=firstitem;
                        two=secondItem;
                    }
                }
                else if(firstitem!=secondItem)
                {
                    maxUnionSet = unity(firstitem, secondItem);
                    if(maxUnionSet.size()!=0)
                    {
                        one=firstitem;
                        two=secondItem;
                    }
                }
        System.out.println("1:"+one+"\n2:"+two);
        return maxUnionSet;
    }

    private HashSet<Integer> unity(Set<Integer> firstSet, Set<Integer> secondSet) {
        HashSet<Integer> resultSet = new HashSet<>();
        for (Integer firstitem : firstSet)
            for (Integer secondItem : secondSet)
                if(firstitem==secondItem)
                    resultSet.add(secondItem);
        return resultSet;
    }
}
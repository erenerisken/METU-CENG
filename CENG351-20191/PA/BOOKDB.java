package ceng.ceng351.bookdb;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class BOOKDB implements IBOOKDB {
    private static String user = "2309953";//"pa1_user";
    private static String password = "080225a3"; //"123456";
    private static String host = "144.122.71.65"; //"localhost";
    private static String database = "db2309953";//"pa1_recitation";
    private static int port = 8084; // 3306;
    private Connection con;

    @Override
    public void initialize() {
        String url = "jdbc:mysql://" + this.host + ":" + this.port + "/" + this.database;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            this.con =  DriverManager.getConnection(url, this.user, this.password);
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    @Override
    public int createTables() {
        int result;
        int n = 0;

        //author(author id:int, author name:varchar(60))
        String authorQuery = "CREATE TABLE author(author_id INT, author_name varchar(60), PRIMARY KEY(author_id))";

        //publisher(publisher id:int, publisher name:varchar(50))
        String publisherQuery = "CREATE TABLE publisher(publisher_id INT, publisher_name varchar(50), PRIMARY KEY(publisher_id))";

        /*book(isbn:char(13), book name:varchar(120), publisher id:int, first publish year:char(4), page count:int, category:varchar(25),
                rating:float) REFERENCES publisher(publisher id)*/
        String bookQuery = "CREATE TABLE book(isbn CHAR(13), book_name VARCHAR(120), publisher_id INT, first_publish_year CHAR(4), " +
                           "page_count INT, category VARCHAR(25), rating FLOAT, PRIMARY KEY(isbn), " +
                            "FOREIGN KEY(publisher_id) REFERENCES publisher(publisher_id))";
        //author of(isbn:char(13),author id:int) REFERENCES book(isbn) author(author id)
        String authorofQuery = "CREATE TABLE author_of(isbn CHAR(13), author_id INT, PRIMARY KEY(isbn, author_id), " +
                                "FOREIGN KEY(isbn) REFERENCES book(isbn), FOREIGN KEY(author_id) REFERENCES author(author_id))";
        //phw1(isbn:char(13), book name:varchar(120), rating: float)
        String phw1Query = "CREATE TABLE phw1(isbn CHAR(13), book_name VARCHAR(120), rating FLOAT, PRIMARY KEY(isbn))";

        try {
            Statement statement = this.con.createStatement();

            //Author Table
            result = statement.executeUpdate(authorQuery);
            System.out.println(result);
            n++;
            //Publisher Table
            result = statement.executeUpdate(publisherQuery);
            System.out.println(result);
            n++;
            //Book Table
            result = statement.executeUpdate(bookQuery);
            System.out.println(result);
            n++;
            //Authorof Table
            result = statement.executeUpdate(authorofQuery);
            System.out.println(result);
            n++;
            //Phw1 Table
            result = statement.executeUpdate(phw1Query);
            System.out.println(result);
            n++;
            //close
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        System.out.println("# of tables created  = " + n);
        return n;
    }

    @Override
    public int dropTables() {
        int result;
        int n = 0;

        String authorQuery = "drop table if exists author";
        String bookQuery = "drop table if exists book";
        String publisherQuery = "drop table if exists publisher";
        String authorofQuery = "drop table if exists author_of";
        String phw1Query = "drop table if exists phw1";


        try {
            Statement statement = this.con.createStatement();

            //phw1
            result = statement.executeUpdate(phw1Query);
            n++;
            System.out.println(result);
            //authorof
            result = statement.executeUpdate(authorofQuery);
            n++;
            System.out.println(result);
            //book
            result = statement.executeUpdate(bookQuery);
            n++;
            System.out.println(result);
            //publisher
            result = statement.executeUpdate(publisherQuery);
            n++;
            System.out.println(result);
            //author
            result = statement.executeUpdate(authorQuery);
            n++;
            System.out.println(result);

            //close
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
        return n;
    }

    //author(author id:int, author name:varchar(60))
    @Override
    public int insertAuthor(Author[] authors) {
        int n = 0;
        for (Author author : authors) {
            int result = 0;

            String query = "INSERT INTO author VALUES(" +
                    author.getAuthor_id() + ", '" +
                    author.getAuthor_name() + "')";

            try {
                Statement st = this.con.createStatement();
                result = st.executeUpdate(query);
                System.out.println(result);
                n++;
                //Close
                st.close();

            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return n;
    }

    /*book(isbn:char(13), book name:varchar(120), publisher id:int, first publish year:char(4), page count:int, category:varchar(25),
                rating:float) REFERENCES publisher(publisher id)*/
    @Override
    public int insertBook(Book[] books) {
        int n = 0;
        for (Book book : books) {
            int result = 0;

            String query = "INSERT INTO book VALUES('" +
                    book.getIsbn() + "', '" +
                    book.getBook_name().replaceAll("'", "''") + "', " +
                    book.getPublisher_id() + ", '" +
                    book.getFirst_publish_year() + "', " +
                    book.getPage_count() + ", '" +
                    book.getCategory() + "', " +
                    book.getRating() + ")";
            System.out.println(query);
            try {
                Statement st = this.con.createStatement();
                result = st.executeUpdate(query);
                System.out.println(result);
                n++;
                //Close
                st.close();

            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return n;
    }

    //publisher(publisher id:int, publisher name:varchar(50))
    @Override
    public int insertPublisher(Publisher[] publishers) {
        int n = 0;
        for (Publisher publisher : publishers) {
            int result = 0;

            String query = "INSERT INTO publisher VALUES(" +
                    publisher.getPublisher_id() + ", '" +
                    publisher.getPublisher_name() + "')";

            try {
                Statement st = this.con.createStatement();
                result = st.executeUpdate(query);
                System.out.println(result);
                n++;
                //Close
                st.close();

            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return n;
    }

    //author of(isbn:char(13),author id:int) REFERENCES book(isbn) author(author id)
    @Override
    public int insertAuthor_of(Author_of[] author_ofs) {
        int n = 0;
        for (Author_of authorOf : author_ofs) {
            int result = 0;

            String query = "INSERT INTO author_of VALUES('" +
                    authorOf.getIsbn() + "', " +
                    authorOf.getAuthor_id() + ")";

            try {
                Statement st = this.con.createStatement();
                result = st.executeUpdate(query);
                System.out.println(result);
                n++;
                //Close
                st.close();

            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return n;
    }

    /*List isbn, first publish year, page count and publisher name of the book(s) which have the maximum number of pages.
    Order the results by isbn in ascending order.*/
    @Override
    public QueryResult.ResultQ1[] functionQ1() {
        ResultSet rs;
        ArrayList<QueryResult.ResultQ1> results = new ArrayList<QueryResult.ResultQ1>(0);
        String query = "SELECT B.isbn, B.first_publish_year, B.page_count, P.publisher_name " +
                       "FROM book B, publisher P " +
                       "WHERE B.publisher_id = P.publisher_id AND B.page_count = (SELECT MAX(page_count) FROM book) " +
                       "ORDER BY B.isbn";
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            while(rs.next()) {
                String isbn = rs.getString("B.isbn");
                String first_publish_year = rs.getString("B.first_publish_year");
                int page_count = rs.getInt("B.page_count");
                String publisher_name = rs.getString("P.publisher_name");
                results.add(new QueryResult.ResultQ1(isbn, first_publish_year, page_count, publisher_name));
            }
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.ResultQ1[] ret = new QueryResult.ResultQ1[results.size()];
        for (int i = 0; i<results.size(); i++)
            ret[i] = results.get(i);
        return ret;
    }
    /*
        For the publishers who have published books that were co-authored by both of the given authors(author1 and author2); list
    publisher id(s) and average page count(s) of all the books these publishers have published.
    Order the results by publisher id in ascending order.
    * */
    /*book(isbn:char(13), book name:varchar(120), publisher id:int, first publish year:char(4), page count:int, category:varchar(25),
                rating:float) REFERENCES publisher(publisher id)*/
    //author of(isbn:char(13),author id:int) REFERENCES book(isbn) author(author id)
    @Override
    public QueryResult.ResultQ2[] functionQ2(int author_id1, int author_id2) {
        ResultSet rs;
        ArrayList<QueryResult.ResultQ2> results = new ArrayList<>(0);
        String innerQuery = "SELECT B.publisher_id " +
                        "FROM book B " +
                        "WHERE B.isbn IN (SELECT A1.isbn FROM author_of A1 WHERE A1.author_id = " + author_id1 + " ) AND " +
                        "B.isbn IN (SELECT A1.isbn FROM author_of A1 WHERE A1.author_id = " + author_id2 + ")";
        String query = "SELECT B2.publisher_id, AVG(B2.page_count) as average_page " +
                        "FROM book B2 " +
                        "WHERE B2.publisher_id IN (" + innerQuery + ") " +
                        "GROUP BY B2.publisher_id";
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            while(rs.next()) {
                int publisher_id = rs.getInt("B2.publisher_id");
                float average_page = rs.getFloat("average_page");
                results.add(new QueryResult.ResultQ2(publisher_id, average_page));
                //results.add(new QueryResult.ResultQ1(isbn, first_publish_year, page_count, publisher_name));
            }
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.ResultQ2[] ret = new QueryResult.ResultQ2[results.size()];
        for (int i = 0; i<results.size(); i++)
            ret[i] = results.get(i);
        return ret;
    }
    /*book(isbn:char(13), book name:varchar(120), publisher id:int, first publish year:char(4), page count:int, category:varchar(25),
                rating:float) REFERENCES publisher(publisher id)*/
    /*
    * List book name, category and rst publish year of the earliest published book(s) of the author(s) whose author name is
    given.
    Order the results by book name, category and rst publish year in ascending order.
    * */
    @Override
    public QueryResult.ResultQ3[] functionQ3(String author_name) {
        ResultSet rs;
        ArrayList<QueryResult.ResultQ3> results = new ArrayList<>(0);
        String earlyBooks = "SELECT B2.isbn " +
                            "FROM book B2, author_of AO, author A " +
                            "WHERE B2.isbn = AO.isbn AND AO.author_id = A.author_id AND A.author_name = '" + author_name + "' AND " +
                            "NOT EXISTS (SELECT B1.isbn FROM book B1, author_of AO1 " +
                            "WHERE B1.isbn = AO1.isbn AND AO1.author_id = A.author_id AND B1.first_publish_year < B2.first_publish_year)";
        String query = "SELECT B.book_name, B.category, B.first_publish_year " +
                        "FROM book B " +
                        "WHERE B.isbn in (" + earlyBooks + ") " +
                        "ORDER BY B.book_name, B.category, B.first_publish_year";
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            while(rs.next()) {
                String book_name = rs.getString("B.book_name");
                String category = rs.getString("B.category");
                String first_publish_year = rs.getString("B.first_publish_year");
                results.add(new QueryResult.ResultQ3(book_name, category, first_publish_year));
                //results.add(new QueryResult.ResultQ1(isbn, first_publish_year, page_count, publisher_name));
            }
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.ResultQ3[] ret = new QueryResult.ResultQ3[results.size()];
        for (int i = 0; i<results.size(); i++)
            ret[i] = results.get(i);
        return ret;
    }
    /*
    * For publishers whose name contains at least 3 words (i.e., "Koc Universitesi Yayinlari"), have published at least 3 books
    and average rating of all their books are greater than(>) 3; list their publisher id(s) and distinct category(ies) they have
    published.
    * */

    @Override
    public QueryResult.ResultQ4[] functionQ4() {
        ResultSet rs;
        ArrayList<QueryResult.ResultQ4> results = new ArrayList<>(0);
        String tmpQuery = "SELECT DISTINCT B.publisher_id " +
                          "FROM book B " +
                          "GROUP BY B.publisher_id " +
                          "HAVING AVG(B.rating) > 3";
        String query = "SELECT DISTINCT B1.publisher_id, B1.category " +
                        "FROM book B1, publisher P " +
                        "WHERE B1.publisher_id = P.publisher_id AND P.publisher_name LIKE '%_ _% %_' AND " +
                        "B1.publisher_id IN (" + tmpQuery + ") " +
                        "ORDER BY publisher_id, category";
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            while(rs.next()) {
                int publisher_id = rs.getInt("publisher_id");
                String category = rs.getString("category");
                results.add(new QueryResult.ResultQ4(publisher_id, category));
                //results.add(new QueryResult.ResultQ1(isbn, first_publish_year, page_count, publisher_name));
            }
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.ResultQ4[] ret = new QueryResult.ResultQ4[results.size()];
        for (int i = 0; i<results.size(); i++)
            ret[i] = results.get(i);
        return ret;
    }

    /*
    * List author id and author name of the authors who have worked with all the publishers that the given author id has worked.
       Order the results by author id in ascending order.
    * */
    @Override
    public QueryResult.ResultQ5[] functionQ5(int author_id) {
        ResultSet rs;
        ArrayList<QueryResult.ResultQ5> results = new ArrayList<>(0);
        String query = "SELECT A.author_id, A.author_name " +
                        "FROM author A " +
                        "WHERE NOT EXISTS(SELECT B.publisher_id " +
                                         "FROM book B, author_of AO " +
                                         "WHERE AO.author_id = " + author_id +" AND AO.isbn = B.isbn " +
                                         "AND NOT EXISTS(SELECT B2.publisher_id " +
                                         "FROM book B2, author_of AO2 " +
                                         "WHERE B.publisher_id = B2.publisher_id AND B2.isbn = AO2.isbn AND AO2.author_id = A.author_id))";
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            while(rs.next()) {
                int author_id_2 = rs.getInt("A.author_id");
                String author_name = rs.getString("A.author_name");
                results.add(new QueryResult.ResultQ5(author_id_2, author_name));
                //results.add(new QueryResult.ResultQ1(isbn, first_publish_year, page_count, publisher_name));
            }
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.ResultQ5[] ret = new QueryResult.ResultQ5[results.size()];
        for (int i = 0; i<results.size(); i++)
            ret[i] = results.get(i);
        return ret;
    }

    /*
    * List author id(s) and isbn(s) of the book(s) written by "Selective" authors. "Selective" authors are those who have only
    worked with publishers that have published their books only.(i.e., they haven't published books of dierent authors)
    Order the results by author id and isbn in ascending order.
    * */
    @Override
    public QueryResult.ResultQ6[] functionQ6() {
        ResultSet rs;
        ArrayList<QueryResult.ResultQ6> results = new ArrayList<>(0);
        String selective = "SELECT DISTINCT AO1.author_id " +
                            "FROM author_of AO1 " +
                            "WHERE NOT EXISTS(SELECT B1.publisher_id " +
                                            "FROM book B1 " +
                                            "WHERE EXISTS(SELECT * " +
                                                        "FROM book B2, author_of AO2 " +
                                                        "WHERE B2.isbn = AO2.isbn AND AO2.author_id = AO1.author_id AND B2.publisher_id = B1.publisher_id)" +
                                            "AND EXISTS(SELECT * " +
                                                            "FROM book B2, author_of AO2 " +
                                                            "WHERE B2.isbn = AO2.isbn AND AO2.author_id != AO1.author_id AND B2.publisher_id = B1.publisher_id))";
        String query = "SELECT AO.author_id, AO.isbn " +
                        "FROM author_of AO " +
                        "WHERE AO.author_id in (" + selective + ") " +
                        "ORDER BY AO.author_id, AO.isbn";
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            while(rs.next()) {
                int author_id = rs.getInt("AO.author_id");
                String isbn = rs.getString("AO.isbn");
                results.add(new QueryResult.ResultQ6(author_id, isbn));
                //results.add(new QueryResult.ResultQ1(isbn, first_publish_year, page_count, publisher_name));
            }
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.ResultQ6[] ret = new QueryResult.ResultQ6[results.size()];
        for (int i = 0; i<results.size(); i++)
            ret[i] = results.get(i);
        return ret;
    }
    /*
    * List publisher id and publisher name of the publishers who have published at least 2 books in 'Roman' category and average
    rating of their books are more than (>) the given value.
    Order the results by publisher id in ascending order.
    * */
    @Override
    public QueryResult.ResultQ7[] functionQ7(double rating) {
        ResultSet rs;
        ArrayList<QueryResult.ResultQ7> results = new ArrayList<>(0);
        String tmp1 = "SELECT B1.publisher_id " +
                      "FROM book B1, book B2 " +
                      "WHERE B1.isbn != B2.isbn AND B2.publisher_id = B1.publisher_id AND B1.category = 'Roman' AND B2.category = 'Roman'";
        String tmp2 = "SELECT B1.publisher_id " +
                      "FROM book B1 " +
                      "GROUP BY B1.publisher_id " +
                      "HAVING AVG(B1.rating) > " + rating;
        String query = "SELECT P.publisher_id, P.publisher_name " +
                        "FROM publisher P " +
                        "WHERE P.publisher_id in (" + tmp1 + ") AND P.publisher_id in (" + tmp2 + ") " +
                        "ORDER BY P.publisher_id";
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            while(rs.next()) {
                int publisher_id = rs.getInt("P.publisher_id");
                String publisher_name = rs.getString("P.publisher_name");
                results.add(new QueryResult.ResultQ7(publisher_id, publisher_name));
                //results.add(new QueryResult.ResultQ1(isbn, first_publish_year, page_count, publisher_name));
            }
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.ResultQ7[] ret = new QueryResult.ResultQ7[results.size()];
        for (int i = 0; i<results.size(); i++)
            ret[i] = results.get(i);
        return ret;
    }
    /*
    * Some of the books in the store have been published more than once: although they have same names(book name),
    they are published with dierent isbns. For each multiple copy of these books, nd the book name(s) with the lowest
    rating for each book name and store their isbn, book name and rating into phw1 table using a single BULK insertion
    query. If there exists more than 1 with the lowest rating, then store them all.
    * */
    /*book(isbn:char(13), book name:varchar(120), publisher id:int, first publish year:char(4), page count:int, category:varchar(25),
                rating:float) REFERENCES publisher(publisher id)*/
    @Override
    public QueryResult.ResultQ8[] functionQ8() {
        int result = 0;

        String multipleQuery = "SELECT B1.book_name " +
                                "FROM book B1, book B2 " +
                                "WHERE B1.book_name = B2.book_name AND B1.isbn != B2.isbn";
        String tmpQuery = "SELECT B.isbn, B.book_name, B.rating " +
                          "FROM book B " +
                          "WHERE B.book_name in (" + multipleQuery + ") " +
                            "AND B.rating = (SELECT MIN(B2.rating) FROM book B2 WHERE B2.book_name = B.book_name)";
        String insertQuery = "INSERT INTO phw1(isbn, book_name, rating) " + tmpQuery;
        try {
            Statement st = this.con.createStatement();
            result = st.executeUpdate(insertQuery);
            System.out.println(result);
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        ResultSet rs;
        ArrayList<QueryResult.ResultQ8> results = new ArrayList<>(0);
        String query = "SELECT * FROM phw1 ORDER BY isbn";
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            while(rs.next()) {
                String isbn = rs.getString("isbn");
                String book_name = rs.getString("book_name");
                float rating = rs.getFloat("rating");
                results.add(new QueryResult.ResultQ8(isbn, book_name, rating));
                //results.add(new QueryResult.ResultQ1(isbn, first_publish_year, page_count, publisher_name));
            }
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.ResultQ8[] ret = new QueryResult.ResultQ8[results.size()];
        for (int i = 0; i<results.size(); i++)
            ret[i] = results.get(i);
        return ret;
    }

    @Override
    public double functionQ9(String keyword) {

        double result = 0;

        String updateQuery = "UPDATE book " +
                             "SET rating = rating + 1 " +
                             "WHERE book_name LIKE '%" + keyword + "%' AND rating <= 4";
        try {
            Statement st = this.con.createStatement();
            result = st.executeUpdate(updateQuery);
            System.out.println(result);
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        ResultSet rs;
        String query = "SELECT * FROM book";
        System.out.println("Keyword is " + keyword);
        result = 0;
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            while(rs.next()) {
                result+=rs.getFloat("rating");
                System.out.println(rs.getString("book_name") + " " + rs.getFloat("rating"));
                //results.add(new QueryResult.ResultQ1(isbn, first_publish_year, page_count, publisher_name));
            }
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        System.out.println("Returning " + result);
        return result;
    }

    @Override
    public int function10() {
        double result = 0;

        String updateQuery = "DELETE FROM publisher " +
                             "WHERE publisher_id NOT IN(" +
                                                        "SELECT publisher_id " +
                                                        "FROM book)";
        try {
            Statement st = this.con.createStatement();
            result = st.executeUpdate(updateQuery);
            System.out.println(result);
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        ResultSet rs;
        String query = "SELECT COUNT(*) as res FROM publisher";
        int ret = 0;
        try {
            Statement st = this.con.createStatement();
            rs = st.executeQuery(query);
            while(rs.next()) {
                ret = rs.getInt("res");
                //results.add(new QueryResult.ResultQ1(isbn, first_publish_year, page_count, publisher_name));
            }
            //Close
            st.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return ret;
    }
}

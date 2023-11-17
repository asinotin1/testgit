/*Single Pattern là một design pattern mà:

Đảm bảo rằng một class chỉ có duy nhất một instance (khởi tạo - mình xin phép để nguyên không dịch từ này)
Và cung cấp một cáchs toàn cầu để truy cấp tới instance đó
vd:  trong ứng dụng có chức năng bật tắt nhạc nền chẳng hạn,
 khi người dùng mở app thì ứng dụng sẽ tự động mở nhạc nền và nếu người dùng muốn tắt thì phải vào setting trong app để tắt nó, 
 trong setting của app cho phép người dùng quản lí việc mở hay tắt nhạc, 
và trong trường hợp này bạn sẽ cần sử dụng singleton để quản lí việc này.*/
#include <string>
#include <iostream>

using namespace std;

class Database
{
private:
    int mRecord;
    string mName;

    // Hàm tạo private để ngăn việc tạo thể hiện từ bên ngoài
    Database(string name)
    {
        mName = name;
        mRecord = 0;
    }

public:
    // Phương thức chỉnh sửa bản ghi trong cơ sở dữ liệu
    void editRecord(string operation)
    {
        cout << "Performing a " << operation <<
                " operation on record " << mRecord <<
                " in database " << mName << endl;
    }

    // Phương thức trả về tên cơ sở dữ liệu
    string getName()
    {
        return mName;
    }

    // Phương thức tĩnh để lấy thể hiện duy nhất của lớp Database
    /**/
    static Database* getInstance(string name)
    {
        // Biến tĩnh mInstance được khởi tạo duy nhất một lần từ database được cung cấp
        static Database mInstance(name);
        return &mInstance;
    }
};

int main()
{
    // Khởi tạo con trỏ database để lưu trữ thể hiện duy nhất của Database
    Database *database;

    // // Lấy thể hiện duy nhất của Database với tên cơ sở dữ liệu là "products"
    // database = Database::getInstance("products");
    // cout << "This is the " << database->getName() << " database." << endl;

    // // Lấy thể hiện duy nhất của Database với tên cơ sở dữ liệu là "employees"
    
    // database = Database::getInstance("employees");
    // cout << "This is the " << database->getName() << " database." << endl;
  database = Database::getInstance("products");
    database->editRecord("update");
    string databasename = database->getName();
    cout << "Database name: " << databasename << endl;
    return 0;
}
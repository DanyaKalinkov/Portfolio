/*Изучить:
Умные указатели (unique_ptr, shared_ptr).
// Доделать
// Доразобрать
*/

  
//-----------------------------------------------------Переменные и типы данных:
  /*
  int age = 25;                                      (обычно 4 байта)
  double price = 99.99;                              (обычно 8 байт, ~15 знаков)
  float cost = 13.4;                                 (обычно 4 байта, ~7 знаков)
  char grade = 'A';                                  (обычно 1 байт, может быть signed/unsigned)
  std::string name = "Danya"; - Строка               (требует #include <string>)
  bool is_active = true; - Логический тип            (true/false) (обычно 1 байт)
  short (short int) короткое целое цисло             (обычно 2 байта)
  long (long int) – длинное целое число              (4 или 8 байт)
  long long (long long int) – очень длинное целое    (обычно 8 байт)

  Модификаторы знака:
  signed – знаковый                                  (по умолчанию для int, short, long)
  unsigned – беззнаковый
  long double – расширенная точность                 (обычно 10 или 16 байт)
  void – отсутствие типа 
  */

//-----------------------------------------------------Ввод и вывод:

/*
std::endl:
   Манипулятор вывода.
   Добавляет символ новой строки ('\n'), чтобы перевести курсор на следующую строку.
   Очищает буфер вывода (вызывает std::flush), гарантируя, 
   что все данные будут немедленно записаны в выходной поток (например, в консоль или файл).
   std::endl — если важен немедленный вывод (логи, отладка).
std::flush:
   Сброс буфера без перевода строки
\n:
   Выводит "Hello, Danya" и переводит строку, но не очищает буфер
   для обычного вывода (быстрее, т.к. не вызывает сброс буфера).
   std:
   это пространство имён (namespace), в котором находится cout.
   cout означает "character output" (вывод символов).
   Оператор << (оператор вставки) передаёт данные в поток вывода.
   Можно использовать несколько раз в одной строке (цепочка вывода).
std::cerr:
   Это стандартный поток для вывода ошибок, определённый в библиотеке <iostream>.
std::clog
   это стандартный поток для логирования (журналирования), который, 
   как и std::cerr, выводит данные в стандартный поток ошибок (stderr), 
   но в отличие от std::cerr, он буферизированный.
   */

// #include <iostream>
// #include <fstream> // Для работы с файлами (std::ofstream)
// #include <string>

// int main () {

//   std::cout << "Hello, Danya" << std::endl;
//   std::cout << "Hello, Danya" << std::flush;
//   std::cout << "Hello, Danya" << '\n';

//   std::string name;
//   std::cout << "Enter your name: \n";
//   std::cin >> name;

//   std::cout << "Your name: " << name << std::endl; // вывод в stdout
//   std::cerr << "Ошибка! Файл не найден!" << std::endl; // Вывод в stderr
//   std::clog << "[INFO] Программа запущена" << std::endl; // Записывает логи

// // Запись логов в файл:
//   std::ofstream logFile("app.log");
//   logFile << "[ERROR] файл не найден" << std::endl;

//   return 0;
// }

//-----------------------------------------------------Условные операторы:

// #include <iostream>

// int main () {

// int x = 10;

// if (x > 0) {
//   std::cout << "Positive" << std::endl;
// } else if (x < 0) {
//   std::cout << "Negative" << std::endl;
// } else {
//   std::cout << "Zero" << std::endl;
// }

//   return 0;
// }
 
//-----------------------------------------------------Циклы: 

// #include <iostream>

// int main () {

// for (int i = 0; i < 10; i++) {
//   std::cout << i;
//   if (i < 9) {
//     std::cout << ", ";
//   }
// }
// std::cout << '\n';

//   return 0;
// }

// while:

// #include <iostream>

// int main () {

// int i = 0;
// // while (++i < 10) {
// while (i < 10) {
//   std::cout << i;
//   if (i < 9) {
//     std::cout << ", ";
//   }
//   i++;
// }
// std::cout << '\n';

//   return 0;
// }

// do-while:

// #include <iostream>

// int main () {

// int i = 0;
// do {
//   std::cout << i;
//   if (i < 9) {
//     std::cout << ", ";
//   }
//   i++;
// } while (i < 0);
// std::cout << '\n';
  
//   return 0;
// }

//-----------------------------------------------------Функции:

// #include <iostream>

// double sum ( double a, double b );
// double add ( double a, double b );

// int main () {

// double num1, num2; 

// std::cout << "Enter num1, num2:" << "\n";
// std::cin >> num1 >> num2;

// std::cout << "Result func sum: " << sum(num1, num2) << std::endl;

// int result_add = add(num1, num2);
// std::cout << "Result func add: " << result_add << std::endl;

//   return 0;
// }

// double sum ( double a, double b ) {
//   return a + b;
// }

// double add ( double a, double b ) {
//   return a - b;
// }

//-----------------------------------------------------Массивы:

// #include <iostream>

// #include <iostream>

// int main () {

// int num[5] = {1, 2, 3, 4, 5};

// for (int i = 0; i < 5; i++) {
//   std::cout << num[i];
//   if (i < 4) {
//     std::cout << ", ";
//   } else {
//     std::cout << ".";
//   }
// } 
// std::cout << std::endl;

// for (int i = 0; i < 5; i++) {
//   std::cout << "num[" << i << "] = " << num[i] << std::endl; 
// }

//   return 0;
// }

//-----------------------------------------------------структуры:

/*Разница структур и классов в том, что в структурах доступ к переменным, 
данным и наследование по умолчанию public, а в классах privat

Структуры в C++ удобны для группировки данных, а если нужна 
более сложная логика с инкапсуляцией, лучше использовать class.*/

// #include <iostream>
// #include <string>

// struct person {
//   std::string name;
//   int age;
//   double height;
// };

// int main () {

// // person people1 = {"Danya", 26, 187.1};
// // person people1 {"Danya", 26, 187.1};
// person people1;
// people1.name = "Danya";
// people1.age = 26;
// people1.height = 187.1;

// std::cout << people1.name << " is " 
//           << people1.age << " years old" << ", and the height is "
//           << people1.height << " cm" << std::endl;

//   return 0;
// }

// Структуры могут содержать методы (как и классы):

// #include <iostream>

// struct Arithmetic {
//   int a = 4;
//   int b = 5;

//   void sum() {
//     std::cout << a + b << std::endl;
//   }
//   int add() {
//     return a - b;
//   }
// };

// int main() {

// Arithmetic ex1;
// ex1.sum();
// std::cout << ex1.add() << std::endl;

//   return 0;
// }

// Структуры могут иметь конструкторы:

// #include <iostream>
// #include <string>

// struct car {
//   std::string NameCar;
//   double SpeedCar;
//   int AgeCar;

//   car(double S, int A) : SpeedCar(S), AgeCar(A) {}
//   car(std::string N) : NameCar(N) {}

//   void OutputCharacteristicsCar() {
//     std::cout << "Age car - " << AgeCar << ", Speed car - " << SpeedCar << std::endl;
//   }
//   void OutputModelCar() {
//     std::cout << "Model car - " << NameCar << std::endl;
//   }
// };

// int main() {

// car CarCharacteristics(256.1, 12);
// CarCharacteristics.OutputCharacteristicsCar();
// car CarModel("Lada");
// CarModel.OutputModelCar();

//   return 0;
// }

// Структуры могут наследоваться (как и классы):

// #include <iostream>

// struct Animals {
//   void MakeSound() {
//     std::cout << "Make sound: ";
//   }
// };

// struct Cat : public Animals {
//   void MakeSoundCat() {
//     std::cout << "Meow-meow!!!" << std::endl;
//   }
// };

// struct Dog : public Animals {
//   void MakeSoundDog() {
//     std::cout << "Bark-Bark!!!" << std::endl;
//   }
// };

// struct Rabbit : public Animals {
//   void MakeSoundRabbit() {
//     std::cout << "Khrum-Khrum!!!" << std::endl;
//   }
// };

// struct Bat : public Rabbit {
//   void MakeSoundBat() {
//     std::cout << "Kar-Kar!!!" << std::endl;
//   }
// };

// int main() {

// Cat Cat;
// Cat.MakeSound();
// Cat.MakeSoundCat();

// Dog Dog;
// Dog.MakeSound();
// Dog.MakeSoundDog();

// std::cout << "\n";

// Bat Bat;
// Bat.MakeSound();
// Bat.MakeSoundRabbit();
// Bat.MakeSound();
// Bat.MakeSoundBat();

//   return 0;
// }

//-----------------------------------------------------Вектор (динамический массив) (#include <vector>)

/*.push_back(40) — это метод вектора, который:
   Увеличивает размер вектора на 1.
   Помещает значение 40 в новую последнюю позицию.*/

/*for (int num : nums) означает:
  "Для каждого элемента num в векторе nums выполнить следующее..."
  На каждой итерации:
  num принимает значение текущего элемента вектора (сначала 10, потом 20, и т.д.).
  Тело цикла (std::cout << num << " ";) выводит num.*/

// #include <iostream>
// #include <vector>

// int main() {

// std::vector<int> vec = {3, 5, 6, -1, 2, 0, -4};
// // std::vector<int> vec { 3, 5, 6, -1, 2, 0, -4 };
// int i = 0;
// vec.push_back(35);
// int size = vec.size();

// for(auto n = vec.begin(); n != vec.end(); n++) {
//   std::cout << *n;
//   if (i < size - 1) {
//     std::cout << ", ";
//   } else {
//     std::cout << ".";
//   }
//   i++;
// }
// std::cout << "\n";

// // i = 0;
// // for(auto n : vec) {
// //   std::cout << n;
// //   if (i < size - 1) {
// //     std::cout << ", ";
// //   } else {
// //     std::cout << ".";
// //   }
// //   i++;
// // }

//   return 0;
// }

// Вектор, созданный из другого вектора:

// #include <iostream>
// #include <vector>

// int main() {

// std::vector<int> vec {3, -1, -5, 2, 5, 75, 1};
// std::vector<int> vec2(vec);
// int i = 0;
// int size = vec2.size();

// for(auto n : vec2) {
//   std::cout << n;
//   if (i < size - 1) {
//     std::cout << ", ";
//   } else {
//     std::cout << ".";
//   }
//   i++;
// }
// std::cout << "\n";

//   return 0;
// }

// Вектор с 6 элементами, каждый равен 10:

// #include <iostream>
// #include <vector>

// int main() {

// std::vector<int> vec(6, 10);
// int size = vec.size();
// int i = 0;

// for(auto n : vec) {
//   std::cout << n;
//   if (i < size - 1) {
//     std::cout << ", ";
//   } else {
//     std::cout << ".";
//   }
//   i++;
// }
// std::cout << "\n";

//   return 0;
// }

// Вектор, созданный из диапазона другого вектора:

// #include <iostream>
// #include <vector> 

// int main() {

// std::vector<int> vec {3, -1, -5, 2, 5, 75, 1};
// std::vector<int> vec2(vec.begin(), vec.end() - 2);
// int size = vec2.size();
// int i =0;

// for(auto n : vec2) {
//   std::cout << n;
//   if (i < size - 1) {
//     std::cout << ", ";
//   } else {
//     std::cout << ".";
//   }
//   i++;
// }
// std::cout << "\n";

//   return 0;
// }

/*std::next - возвращает итератор, смещённый на указанное количество позиций 
вперёд от заданного итератора.*/

// #include <iostream>
// #include <vector>

// int main() {

// std::vector<int> vec {3, -1, -5, 2, 5, 75, 1};
// std::cout << *(vec.begin() + 3) << std::endl;

// std::cout << *std::next(vec.begin(), 2) << std::endl;

//   return 0;
// }

// Доступ к элементам:
/*Метод data() возвращает указатель на внутренний массив, 
который использует вектор для хранения своих элементов. 
Это полезно, когда вам нужно передать данные вектора в функции, 
работающие с обычными C-массивами.*/ 

// #include <iostream>
// #include <vector>

// int main () {

// std::vector<int> vec{2, 43, 54, 23, 54, 24};

// std::cout << vec.at(3) << std::endl; // Доступ по индексу с проверкой границ
// std::cout << vec.front() << std::endl; // Первый элемент
// std::cout << vec.back() << std::endl; // Последний элемент

// int* data = vec.data(); // Получение указателя на данные
// std::cout << *data << std::endl;

// std::cout << *vec.data() << std::endl;

//   return 0;
// }

// Генерация массива со случайными числами:
// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>

// int main () {

// std::vector<int> vec;

// std::srand(std::time(0));

// int z = 0;
// std::cout << "Введите кол-во эл-от массива: ";
// std::cin >> z;

// for (int y = 0; y < z; y++) {
// // int randomNum = std::rand() % 100;
// vec.push_back(std::rand() % 100);
// }
// int size = vec.size();

// int i = 0;
// for(auto n : vec) {
//   std::cout << n;
//   if (i < size - 1) {
//     std::cout << ", ";
//   } else {
//     std::cout << ".";
//   }
//   i++;
// }
// std::cout << "\n";

//   return 0;
// }

// Доразобрать:
//-----------------------------------------------------operator

/*В вашем примере класс adder перегружает оператор вызова функции (), 
что позволяет использовать объект этого класса как функцию. 
Такие объекты называются функторами (или функциональными объектами).*/

// #include<iostream>

// class adder {
//   public:
//     // Перегружаем оператор ():
//     int operator()(int a, int b) const {
//       return a + b;
//     }
// };

// int main() {

// adder adder;

// // Вызываем объект как функцию:
// int result = adder(1, 3); // компилятор преобразует это в adder.operator()(3, 5)
// std::cout << result << std::endl;

//   return 0;
// }

// #include <iostream>

// class adder {
//   public:
//     int operator()(int a, int b) const {
//       return a + b;
//     }
// };

// int main() {

// adder add;
// int result = add(3, 65);
// std::cout << result << std::endl;
// // std::cout << add(4, 5) << std::endl;

//   return 0;
// }

//-----------------------------------------------------Классы и объекты (ООП)

/*private: - модификатор доступа, означающий, что следующие поля доступны только внутри класса.
  public: - модификатор доступа, означающий, что следующие методы доступны извне класса.
  protected: - модификатор доступа, означающий, что следующие методы доступны внутри класса и в классах-наследниках.
  */
/*Person(std::string n, int a) - Это объявление конструктора.
  Конструктор имеет:
  Имя, совпадающее с именем класса (всегда) (Person).
  Конструктор не имеет типа возвращаемого значения (даже void).
  набор параметров
  : name(n), age(a) - Это список инициализации (initialization list) — специальный синтаксис C++ для инициализации полей класса.
  {} - Пустое тело конструктора. Здесь могла бы быть дополнительная логика.
  пример, когда {} не пустые: 
    Person(std::string n, int a) : name(n) {
    if (a >= 0) age = a;  // Проверка корректности возраста
    else age = 0;
}
  функции внутри класса (void greet()) называются методы.
  Созданные в функции main переменные (person people1("Danya", 26)); называются объектами:
  person people1("Danya", 26) - вызываем конструктор с параметрами:
  "Danya" - передаётся в параметр n.
  26 - передаётся в параметр a.
  person1.greet() - вызываем метод greet() для объекта person1.
;*/
  /*Основные концепции в этом коде:
  Класс - пользовательский тип данных (Person).
  Инкапсуляция - разделение доступа (private/public/protected).
  Конструктор - метод для инициализации объекта.
  Метод - функция внутри класса (greet()). 
  Объект - экземпляр класса (person1).*/

  /*В классе может быть несколько конструкторов. 
  Это называется перегрузкой конструкторов (constructor overloading). 
  Каждый конструктор должен иметь уникальную сигнатуру (разный набор параметров).*/

// #include <iostream>
// #include <string>

// class persons {
//   private:
//     std::string name;
//     int age;
//     double height;
//   public:
//     persons(std::string n, int a, double h) : name(n), age(a), height(h) {}
//     persons(double h) : height(h) {}

//     void OutputInfo() {
//       std::cout << "Name is " << name <<", age is " << age 
//                 << ", height is " << height << std::endl;
//     }
//     void OutputHeight() {
//       std::cout << "Height is " << height << std::endl;
//     }
// };

// int main() {

// persons personOneInfo("Danya", 45, 174);
// personOneInfo.OutputInfo();

// persons personOneHeight(174);
// personOneHeight.OutputHeight();

//   return 0;
// }

// Примеры программ с классами

// #include <iostream>

// class Addition {
//   private:
//     int number1, number2, result;
//     double number3, number4;
//   public:
//     Addition(int n1, int n2) {
//       if (n1 > 0 && n2 > 0) {
//         number1 = n1;
//         number2 = n2;
//         result = n1 + n2;
//         std::cout << result << std::endl;
//       } else {
//         number1 = 0;
//         number2 = 0;
//         std::cout << "Переменные инициализтированы нулями" << std::endl;
//       }
//     }
//     Addition(double n3, double n4) : number1((n3 > 0) ? n3 : 0), number2((n4 > 0) ? n4 : 0) {
//       std::cout << n3 + n4 << std::endl;
//     }

//     void add() {
//       std::cout << number1 + number2 << std::endl;
//     }

//     int add1() {
//       return number1 + number2;
//     }
// };

// int main() {

// Addition ex1(45, 2);
// ex1.add();
// std::cout << ex1.add1() << std::endl;

// Addition ex2(2.9, 2.2);

//   return 0;
// }

// #include <iostream>
// #include <string>

// class Person {
//   private:
//     std::string Name;
//     int Age;
//   public:
//     Person(std::string N, int A) : Name(N), Age(A) {}

//   void greet() {
//     std::cout << "Hello, my name is " << Name << ", I'm " << Age << " years old" << std::endl;
//   }

//   void birthday() {
//     Age++;
//     std::cout << "Happy birthday ," << Name << ", you turned " << Age << " years old" << std::endl;
//   }
// };

// int main() {

// Person Person("Danya", 27);
// Person.greet();
// Person.birthday();
// Person.greet();

//   return 0;
// }

// #include <iostream>
// #include <cmath>

// class Calculation {
//   private:
//     int num1;
//   public: 

//     int degree(int num, int exponent) {return pow(num, exponent);}
// };

// int main () {

// Calculation ex1;
// std::cout << ex1.degree(2, 5) << std::endl;

//   return 0;
// }

// Пример класса с (Наследование и полиморфизм):
/*Наследование и полиморфизм — ключевые концепции объектно-ориентированного 
программирования (ООП), которые позволяют создавать гибкие и расширяемые программы.
*/

/*Наследование позволяет создавать новый класс 
на основе существующего, перенимая его свойства и методы:
*/

// #include <iostream>

// class Animals {
//   public:
//     void MakeSound() {
//       std::cout << "Make sound: ";
//   }
// };

// class Cat : public Animals {
//   public:
//     void MakeSoundCat() {
//       std::cout << "Meow-meow!!!" << std::endl;
//   }
// };

// class Dog : public Animals {
//   public:
//     void MakeSoundDog() {
//       std::cout << "Bark-Bark!!!" << std::endl;
//   }
// };

// class Rabbit : public Animals {
//   public:
//     void MakeSoundRabbit() {
//       std::cout << "Khrum-Khrum!!!" << std::endl;
//   }
// };

// class Bat : public Rabbit {
//   public:
//     void MakeSoundBat() {
//       std::cout << "Kar-Kar!!!" << std::endl;
//   }
// };

// int main() {

// Cat Cat;
// Cat.MakeSound();
// Cat.MakeSoundCat();

// Dog Dog;
// Dog.MakeSound();
// Dog.MakeSoundDog();

// std::cout << "\n";

// Bat Bat;
// Bat.MakeSound();
// Bat.MakeSoundRabbit();
// Bat.MakeSound();
// Bat.MakeSoundBat();

//   return 0;
// }

// Полиморфизм позволяет объектам разных классов обрабатываться через общий интерфейс:

/*
Зачем нужен virtual ~Animals() = default - 
Если класс предназначен для наследования (особенно если есть виртуальные методы), 
то деструктор тоже должен быть виртуальным. Это гарантирует, 
что при удалении объекта через указатель на базовый класс 
будет вызван правильный деструктор (сначала производного класса, потом базового).
*/

// #include <iostream>

// class Animals {
//   public:
//     virtual void MakeSound() {
//       std::cout << "This animal is a ";
//     }
//     virtual ~Animals() = default;
// };

// class Cat : public Animals {
//   public:
//     void MakeSound() override {
//       std::cout << "cat and it makes a sound: Meow-meow!!!" << std::endl;
//     }
// };

// class Dog : public Animals {
//   public:
//     void MakeSound() override {
//       std::cout << "dog and it makes a sound: Bark-bark!!!" << std::endl;
//     }
// };

// int main() {

// Animals Animal;
// Animal.MakeSound();
// std::cout << std::endl;

// Animals *Animal1 = new Animals();
// Animal1->MakeSound();
// Animals *Animal2 = new Cat();
// Animal2->MakeSound();

// delete Animal1;
// delete Animal2;

// Animals *AnimalsDiversity[4];
// AnimalsDiversity[0] = new Animals();
// AnimalsDiversity[1] = new Cat();
// AnimalsDiversity[2] = new Animals();
// AnimalsDiversity[3] = new Dog();

// for(int i = 0; i < 4; i++) {
//   AnimalsDiversity[i]->MakeSound();
//   delete AnimalsDiversity[i];
// }

// // for(int i = 0; i < 4; i++) {
// //   delete AnimalsDiversity[i];
// // }

//   return 0;
// }

// Абстрактные классы и чистые виртуальные функции:

/*
Если метод должен быть обязательно переопределён в наследниках
Animal теперь абстрактный класс, и его нельзя создать:
Animal animal;  // Ошибка!

Каждый объект класса с виртуальными функциями имеет скрытый указатель на таблицу, 
содержащую адреса этих функций.
*/

// #include <iostream>

// class Animals {
//   public:
//     virtual void MakeSound() = 0; // Чистая виртуальная функция
//     virtual ~Animals() = default;
// };

// class Cat : public Animals {
//   public:
//     void MakeSound() override {
//       std::cout << "This is cat" << std::endl;
//     }
// };

// class Dog : public Animals {
//   public:
//     void MakeSound() override {
//       std::cout << "This is dog" << std::endl;
//     }
// };

// int main() {

// // Animals Animal; // Ошибка

// Animals *Animal1 = new Cat();
// Animal1->MakeSound();
// delete Animal1;

// Animals *AnimalsDiversiry[2];
// AnimalsDiversiry[0] = new Cat();
// AnimalsDiversiry[1] = new Dog();

// for(int i = 0; i < 2; i++) {
//   AnimalsDiversiry[i]->MakeSound();
//   delete AnimalsDiversiry[i];
// }

//   return 0;
// }

// Переопределение методов (override):
/*Ключевое слово override явно указывает, что метод переопределяет виртуальный метод 
базового класса.

Зачем это нужно?:
Защита от опечаток (если в базовом классе нет такого метода, компилятор выдаст ошибку).
Улучшает читаемость кода.*/

// #include <iostream>

// class Animals {
//   public:
//     virtual void MakeSound() {
//       std::cout << "This animal is ";
//     }
// };

// class Cat : public Animals {
//   public:
//     void MakeSound() override { // Явное указание переопределения (override)
//       std::cout << "cat" << std::endl;
//     }
// };

// int main() {

// Animals *Animal1 = new Cat();
// Animal1->MakeSound();

//   return 0;
// }

// Пример полиморфизма с динамическим выделением памяти (с деструктором и умными указателями):

/*
~Circle() { std::cout << "Circle destroyed" << std::endl; } - 
Это деструктор класса Circle, который выводит сообщение "Circle destroyed" при уничтожении объекта.
*/
/*
std::make_unique — это функция-шаблон из стандартной библиотеки C++ (начиная с C++14), 
которая создаёт объект в динамической памяти и возвращает умный указатель std::unique_ptr на этот объект.
Создаёт объект с помощью оператора new.

Гарантирует исключительную (unique) ответственность за владелецкий указатель, 
то есть объект будет автоматически уничтожен, когда unique_ptr выйдет из области видимости.

Удобна тем, что сокращает код и уменьшает риск утечки памяти по сравнению 
с явным вызовом new и созданием unique_ptr.

Позволяет использовать полиморфизм, как в вашем примере с классами Shapes, Circle, Square. 
При этом хранение объектов в контейнере std::vector<std::unique_ptr<Shapes>> безопасно 
и корректно управляет временем жизни объектов.
*/

// #include <iostream>
// #include <vector>
// #include <memory> // std::unique_ptr

// class Shapes {
//   public:
//     virtual void Draw() = 0;
//     virtual ~Shapes() = default;
// };

// class Circle : public Shapes {
//   public:
//     void Draw() override {
//       std::cout << "Draw circle" << std::endl;
//     }
//     ~Circle() { std::cout << "Circle destroyed" << std::endl; } 
// };

// class Square : public Shapes {
//   public:
//     void Draw() override {
//       std::cout << "Draw square" << std::endl;
//     }
//     ~Square() { std::cout << "Square destroyed" << std::endl; }
// };

// int main() {

// // std::vector<Shapes*> Shape;
// // Shape.push_back(new Circle());
// // Shape.push_back(new Square());

// // for(Shapes* n : Shape) {
// //   n->Draw();
// //   delete n;
// // }

// std::vector<std::unique_ptr<Shapes>> Shape;
// Shape.push_back(std::make_unique<Circle>());
// Shape.push_back(std::make_unique<Square>());

// // Если не указать тут ссылку, то будет попытка копирования unique_ptr, а это невозможно:
// for(std::unique_ptr<Shapes>& n : Shape) { 
//   n->Draw();
// }
// std::cout << std::endl;

// // Вывод адресов указателей:
// for(std::unique_ptr<Shapes>& n : Shape) {
//   std::cout << n.get() << std::endl;
// }

//   return 0;
// }

// Создание интерфейсов (контрактов для классов). Пример: Интерфейс для фигур::
/*
Абстрактные классы часто используются как интерфейсы, 
которые задают обязательные методы для всех наследников.
*/

/*
Зачем clear() в этом коде:
После ручного удаления всех объектов через delete указатели в векторе становятся "висячими" (указывают на освобождённую память)
clear() очищает вектор, убирая эти висячие указатели
Это хорошая практика, чтобы случайно не попытаться использовать эти указатели снова

В данном конкретном случае, когда вектор shapes является локальной переменной 
функции main() и программа сразу после этого завершается, clear() не обязателен - 
память всё равно будет освобождена при завершении программы
Однако в более общем случае, если бы вектор был членом класса или программа продолжала 
работать, clear() был бы хорошей практикой для избежания проблем с висячими указателями

Как показано в вашем закомментированном коде, использование std::unique_ptr было бы 
лучше - тогда не нужно было бы вручную удалять объекты, и clear() работал бы корректно автоматически
*/

// #include <iostream>
// #include <vector>
// #include <memory>

// class Shapes {
//   public:
//     virtual void Draw() = 0;
//     virtual double Area() = 0;
//     virtual ~Shapes() = default; // Виртуальный деструктор для более точного освобождения памяти
// };

// class Circle : public Shapes {
//   private:
//     double Radius;
//   public:
//     Circle(double R) : Radius(R) {}

//     void Draw() override {
//       std::cout << "Draw Circe: ";
//     }
//     double Area() override {
//       return 3.14 * Radius * Radius;
//     }
// };

// class Square : public Shapes {
//   private:
//     double Side;
//   public:
//     Square(double S) : Side(S) {}

//     void Draw() override {
//       std::cout << "Draw Square: ";
//     }
//     double Area() override {
//       return Side * Side;
//     }
//   };

// int main() {

// // std::vector<Shapes*> Shape;
// // Shape.push_back(new Circle(4.4));
// // Shape.push_back(new Square(4.5));

// // for(Shapes* n : Shape) {
// //   n->Draw();
// //   std::cout << n->Area() << std::endl;
// //   delete n;
// // }

// // // Вывод адресов указателей:
// // for(Shapes* n : Shape) {
// //   std::cout << &n << std::endl;
// // }

// // // Вывод адресов объектов, на которые указывают указатели:
// // for(Shapes* n : Shape) {
// //   std::cout << n << std::endl;
// // }

// // Shape.clear(); // Очистить вектор, чтобы избежать висячих указателей

// std::vector<std::unique_ptr<Shapes>> Shape;
// Shape.push_back(std::make_unique<Circle>(5.5));
// Shape.push_back(std::make_unique<Square>(2.2));

// for(std::unique_ptr<Shapes>& n : Shape) {
//   n->Draw();
//   std::cout << n->Area() << std::endl;
// }

// // n.get() — сырой указатель на управляемый объект (Shapes).
// // Вывод адресов объектов:
// for(std::unique_ptr<Shapes>& n : Shape) {
//   std::cout << n.get() << std::endl;
// }

//   return 0;
// }

// Примеры программы, с использованием вложенного класса в C++:

// Пример с сеттерами и геттерами:
// #include <iostream>
// #include <string>

// class Computer {
//   private:
//     std::string Model;

//     class Processor {
//       private:
//         std::string Brand;
//         double ClockSpeed;
//     public:
//       Processor(const std::string& b, double s) : Brand(b), ClockSpeed(s) {}

//       void DisplayInfo() const {
//         std::cout << "Процессор: " << Brand << ", тактовая частота: " 
//         << ClockSpeed << "GHz" << std::endl;
//       }
//       std::string GetBrand() const {return Brand;}
//       double GetClockSpeed() const {return ClockSpeed;}

//       void SetBrand(const std::string& newBrand) {Brand = newBrand;}
//       void SetClockSpeed(double speed) {ClockSpeed = speed;}
//     };
//     Processor Cpu; // объект вложенного класса как член внешнего класса

//     public:
//       Computer(const std::string& m, const std::string& CpuBrand, double CpuSpeed) 
//       : Model(m), Cpu(CpuBrand, CpuSpeed) {}

//       void ShowComputerInfo() const {
//         std::cout << "Модель компьютера: " << Model << std::endl;
//         Cpu.DisplayInfo();
//       }
//       void Overclock(double additionalSpeed) {
//         std::cout << "Разгон процессора с " <<Cpu.GetClockSpeed() << "GHz до ";

//         Cpu.SetClockSpeed(Cpu.GetClockSpeed() + additionalSpeed);
//         Cpu.SetBrand("Overclocked " + Cpu.GetBrand());
//         std::cout << Cpu.GetClockSpeed() << "GHz" << std::endl;
//       }
// };

// int main () {

// Computer myPC("SuperComp X1000", "Intel Core i9", 3.5);
// myPC.ShowComputerInfo();

// myPC.Overclock(0.5);
// myPC.ShowComputerInfo();

//   return 0;
// }

// #include <iostream>
// #include <string>

// class Car {
//   private:  
//     std::string ModelCar;
//   class Engine {
//     private:
//       double Power;
//     public:
//       Engine(double P) : Power(P) {}

//       void SetPowerEngine(double NewPowerEngine) {Power = NewPowerEngine;}
//       double GetPowerEngine() {return Power;}
//   };
//   Engine JZ;

//   public:
//     Car(std::string M, double PowerEngine) : ModelCar(M), JZ(PowerEngine) {}

//     void GetInfoCar() {
//       std::cout << "Model car is " << ModelCar << ", power engine is " 
//                 << JZ.GetPowerEngine() << std::endl;
//     }

//     void SetAdditionalPowerEngine(double AdditionalPowerEngine) {
//       std::cout << "engine boost by " << AdditionalPowerEngine << " forces" << std::endl;
//       JZ.SetPowerEngine(JZ.GetPowerEngine() + AdditionalPowerEngine);
//     }
//     void GetNewPowerEngine() {
//       std::cout << "PowerEngine after engine boost - " << JZ.GetPowerEngine() << std::endl;
//     }
// };

// int main() {

// Car MyCar("Lada", 220);
// MyCar.GetInfoCar();
// MyCar.SetAdditionalPowerEngine(20);
// MyCar.GetNewPowerEngine();
// MyCar.GetInfoCar();

//   return 0;
// }

// Пример с friend class

/*
Дружественные функции и классы — это механизм, который позволяет нарушить инкапсуляцию 
для избранных функций или классов, давая им прямой доступ к private и protected членам.
*/

/*
Использование const std::string& в этих конструкторах — это:
Оптимизация (избегаем копирования строк)
Безопасность (const защищает от случайного изменения)
Стандартная практика в C++ для передачи объектов, которые не нужно изменять.
*/

// #include <iostream>
// #include <string>

// class Computer {
//   private:
//     std::string Model;
//   public:
//     class Processor {
//       friend class Computer;
//       private:
//         std::string Brand;
//         double ClockSpeed;
//       public:
//         Processor(const std::string& B, double C) : Brand(B), ClockSpeed(C) {}

//         void CpuInfo() const {
//           std::cout << "Cpu Brand is " << Brand << ", Cpu ClockSpeed is " 
//                     << ClockSpeed << " Hertz" << std::endl;
//         }
//     };
//     Processor Cpu;
//     public:
//       Computer(const std::string& M, const std::string& CpuBrand, double CpuClockSpeed) : 
//                Model(M), Cpu(CpuBrand, CpuClockSpeed) {}

//       void PcInfo() const {
//         std::cout << "Model Pc is " << Model << std::endl;
//         Cpu.CpuInfo();
//       }
//       void Overclock(double AdditionalClockSpeed) {
//         std::cout << "Processor overclocking from " << Cpu.ClockSpeed << " Hertz to ";
//         Cpu.ClockSpeed += AdditionalClockSpeed;
//         Cpu.Brand = "Overclocked " + Cpu.Brand;
//         std::cout << Cpu.ClockSpeed << " Hertz" <<std::endl;
//       }
// };

// int main() {

// Computer MyPc("ASUS TUF GAMING A15", "Intel Core i9", 4.0);
// // MyPc.Cpu.CpuInfo(); // Форма записи, которая становится возможной при использовании friend class
// MyPc.PcInfo();
// MyPc.Overclock(0.5);
// MyPc.PcInfo();

//   return 0;
// }

// Дружественная функция для перегрузки оператора:

/*
friend std::ostream& operator<<(std::ostream& OS, const Vector& V):
(Дружественная функция для перегрузки оператора (<<)
(Объявляется внутри класса, но не является его методом)

friend - даёт функции доступ к приватным полям класса
std::ostream& operator<< - объявление функции перегрузки оператора

std::ostream& - возвращаемый тип:
std::ostream - тип выходного потока (cout, файлы, строки)
& - возвращается ссылка, а не копия объекта
Почему ссылка? Чтобы можно было делать цепочки: cout << a << b << c

operator<< - имя функции:
operator - ключевое слово для перегрузки операторов
<< - конкретный оператор для перегрузки
Это бинарный оператор (принимает два аргумента)

(std::ostream& OS, const Vector& V) - параметры:
std::ostream& OS - первый операнд (выходной поток)
const Vector& V - второй операнд (объект для вывода)
& - передача по ссылке (избегаем копирования)
const - гарантия, что объект V не будет изменен

Как это работает:
std::cout << myVector;
Компилятор преобразует это в:
operator<<(std::cout, myVector);

friend Vector operator+(const Vector& V1, const Vector& V2):
(Дружественная функция для перегрузки оператора (+)

friend - аналогично первому случаю
Даёт доступ к приватным полям класса Vector
Vector - возвращаемый тип
Функция возвращает новый объект типа Vector
Это результат сложения двух векторов
Возвращается по значению (создается новый объект)
operator+ - имя функции
+ - оператор сложения
Также бинарный оператор
(const Vector& V1, const Vector& V2) - параметры
const Vector& V1 - первый вектор для сложения
const Vector& V2 - второй вектор для сложения
Оба параметра передаются по константной ссылке
const - гарантия, что исходные вектора не изменятся

Как это работает:
Vector result = vector1 + vector2;
Компилятор преобразует это в:
Vector result = operator+(vector1, vector2);

std::ostream& operator<<(std::ostream& OS, const Vector& V):
(Реализация перегрузки оператора (<<))

std::ostream& - возвращает ссылку на поток вывода
operator<< - имя перегружаемого оператора
(std::ostream& OS, const Vector& V) - параметры: поток вывода и константная ссылка на Vector

OS << "(" << V.Var1 << ", " << V.Var2 << ")" - Прямой доступ к private полям!
Благодаря friend имеем прямой доступ к V.Var1 и V.Var2
return  OS - Возвращаем поток вывода (позволяет цепочки вывода: cout << a << b)

Vector operator+(const Vector& V1, const Vector& V2):
(Реализация перегрузки оператора (+))

Vector - возвращает новый объект Vector
operator+ - имя перегружаемого оператора
(const Vector& V1, const Vector& V2) - два вектора для сложения

  return Vector(V1.Var1 + V2.Var1, V1.Var2 + V2.Var2) - Прямой доступ к private полям!

*/

// #include <iostream>

// class Vector {
//   private:  
//     double Var1, Var2;
//   public:
//     Vector(double Var1 = 0, double Var2 = 0) : Var1(Var1), Var2(Var2) {}
  
//     friend std::ostream& operator<<(std::ostream& OS, const Vector& V);

//     friend Vector operator+(const Vector& V1, const Vector& V2);
// };

// std::ostream& operator<<(std::ostream& OS, const Vector& V) {
//   OS << "(" << V.Var1 << ", " << V.Var2 << ")";
//   return  OS;
// }

// Vector operator+(const Vector& V1, const Vector& V2) {
//   return Vector(V1.Var1 + V2.Var1, V1.Var2 + V2.Var2); 
// }

// int main() {

// Vector V1(1, 2), V2(3, 4);
// Vector V3 = V1 + V2;

// std::cout << "V1:" << V1 << std::endl;
// std::cout << "V2: " << V2 << std::endl;
// std::cout << "V1 + V2" << V3 << std::endl;

//   return 0;
// }

// Дружественный класс для тесного взаимодействия:

// #include <iostream>

// class Engine {
//   private:
//     double HorsePower;
//     bool IsRunning;

//     friend class Car;
//   public:
//     Engine(double HP) : HorsePower(HP), IsRunning(false) {}
// };

// class Car {
//   private:
//     Engine MyEngine;
//   public:
//     Car() : MyEngine(150.0) {}

//     void Start() {
//       MyEngine.IsRunning = true;
//       std::cout << "Car started! Engine power: " << MyEngine.HorsePower << " HP" << std::endl;
//     }

//     void Stop() {
//       MyEngine.IsRunning = false;
//       std::cout << "Car stoped" << std::endl;
//     }
// };

// int main() {

// Car MyCar;
// MyCar.Start();
// MyCar.Stop();

//   return 0;
// }

/*
friend double determinant(const Matrix& m) - Дружественная функция имеет доступ к приватным данным
double getDeterminantSlow() const - Обычный метод для сравнения
*/

// #include <iostream>

// class Matrix {
//   private:
//     double data[2][2];
//   public:
//     Matrix(double a = 0, double b = 0, double c = 0, double d = 0) {
//       data[0][0] = a; data[0][1] = b;
//       data[1][0] = c; data[1][1] = d;
//     }

//     friend double Determinant(const Matrix& M);

//     double GetDeterminantSlow() const {
//       return data[0][0] * data[1][1] - data[0][1] * data[1][0];
//     }
// };

// double Determinant(const Matrix& M) {
//   return M.data[0][0] * M.data[1][1] - M.data[0][1] * M.data[1][0];
// }

// int main() {

// Matrix MyMatrix(1, 2, 3, 4);

// std::cout << "Determinant (friend): " << Determinant(MyMatrix) << std::endl;
// std::cout << "Determinant (method): " << MyMatrix.GetDeterminantSlow() << std::endl;

//   return 0;
// }

// #include <iostream>

// class Car {
//   private:
//     double HorsePower;
//   public:
//     Car(double HP = 0) { HorsePower = HP; }

//     friend double GetHorsePower(Car& C); 
// };

// double GetHorsePower(Car& C) { C.HorsePower += 1; return C.HorsePower; }

// int main() {

// Car MyCar(29);

// std::cout << GetHorsePower(MyCar) << std::endl;

//   return 0;
// }

// getters, setters:

// Геттеры - это методы, которые возвращают значение приватного поля класса.
// Сеттеры - это методы, которые устанавливают значение приватного поля с возможной проверкой.

// #include <iostream>
// #include <string>

// #include <iostream>
// #include <string>

// class Car {
//   private:
//     std::string CarModel;
//     double CarSpeed;
//   public:

//     // Сеттеры:
//     void SetCarModel(std::string NewCarModel) {
//       CarModel = NewCarModel;
//     }
//     void SetCarSpeed(double NewCarSpeed) {
//         CarSpeed = NewCarSpeed;
//     }

//     // Геттеры:
//     std::string GetCarModel() {
//       return CarModel;
//     }
//     double GetCarSpeed() {
//       return CarSpeed;
//     }
// };

// int main() {

// Car Lada;
// Lada.SetCarModel("Vesta");
// Lada.SetCarSpeed(260);

// std::cout<< "Car model is " << Lada.GetCarModel() << std::endl;
// std::cout << "Car speed is " << Lada.GetCarSpeed() << std::endl;

//   return 0;
// }

// #include <iostream>
// #include <string>

// class Car {
//   private:
//     std::string ModelCar;
//     double WeightCar;
//     double SpeedCar;

//     class Engine {
//       private:
//         std::string ModelEngine;
//         double PowerEngine;
//       public:
//         void SetModelEngine(std::string NewModelEngine) {ModelEngine = NewModelEngine;}
//         void SetPowerEngine(double NewPowerEngine) {PowerEngine = NewPowerEngine;}

//         std::string GetModelEngine() {return ModelEngine;}
//         double GetPowerEngine() {return PowerEngine;}
//     };
//     class TransmissionBox {  
//       private:
//         double SpeedTransmissionBox;
//       public:
//         void SetSpeedTransmissonBox(double NewSpeedTransmissionBox) {
//           SpeedTransmissionBox = NewSpeedTransmissionBox;
//         }
//         double GetSpeedTransmissionBox() {return SpeedTransmissionBox;}
//     };
//     class Accumulator {
//       private:
//         double AchAccumulator;
//       public:
//         void SetAchAccumulator(double NewSetAchAccumulator) {
//           AchAccumulator = NewSetAchAccumulator;
//         }
//         double GetAchAccumulator() {return AchAccumulator;}
//     };

//     Engine JZ;
//     TransmissionBox R154;
//     Accumulator VartaUnattended;

//     public:
//       void SetModelCar(std::string NewModelCar) {ModelCar = NewModelCar;}
//       void SetWeightCar(double NewWeightCar) {WeightCar = NewWeightCar;}
//       void SetSpeedCar(double NewSpeedCar) {SpeedCar = NewSpeedCar;}

//       std::string GetModelCar() {return ModelCar;}
//       double GetWeightCar() {return WeightCar;}
//       double GetSpeedCar() {return SpeedCar;}

//       // Engine:
//       void SetModelEngine(std::string NewModelEngine) {JZ.SetModelEngine(NewModelEngine);}
//       void SetPowerEngine(double NewPowerEngine) {JZ.SetPowerEngine(NewPowerEngine);}

//       void GetModelEngine() {std::cout << JZ.GetModelEngine() << std::endl;}
//       void GetPowerEngine() {std::cout << JZ.GetPowerEngine() << std::endl;}

//       // TransmissionBox:
//       void SetSpeedTransmissionBox(double NewSpeedTransmissionBox) {
//         R154.SetSpeedTransmissonBox(NewSpeedTransmissionBox);
//       }
//       void GetSpeedTransmissionBox() {std::cout << R154.GetSpeedTransmissionBox() << std::endl;}

//       // Accumulator:
//       void SetAchAccumulator(double NewAchAccumulator) {
//         VartaUnattended.SetAchAccumulator(NewAchAccumulator);
//       }
//       void GetAchAccumulator() {std::cout << VartaUnattended.GetAchAccumulator() << std::endl;}
// };

// int main() {

// Car Car1;
// Car1.SetModelCar("Lada");
// Car1.SetWeightCar(2500);
// Car1.SetSpeedCar(250);

// std::cout << Car1.GetModelCar() << std::endl;
// std::cout << Car1.GetWeightCar() << std::endl;
// std::cout << Car1.GetSpeedCar() << std::endl;

// // Engine:
// Car1.SetModelEngine("JZ");
// Car1.SetPowerEngine(360);

// Car1.GetModelEngine();
// Car1.GetPowerEngine();

// // TransmissionBox:
// Car1.SetSpeedTransmissionBox(7);
// Car1.GetSpeedTransmissionBox();

// // Accumulator:
// Car1.SetAchAccumulator(455.1);
// Car1.GetAchAccumulator();


//-----------------------------------------------------getters и setters в реализации валидации и логирования:

// Валидация в Setter'ах
// Класс User, где setter'ы проверяют корректность данных перед установкой

/*
Ключевое слово const после объявления метода означает, 
что этот метод не изменяет состояние объекта.

Почему это важно:
Безопасность: Гарантирует, что геттеры не изменят данные объекта
Ясность кода: Показывает намерение, что метод только читает данные
Возможность использования с const объектами:

const User user("John", 25, "john@email.com");
string name = user.GetName(); // Работает только если GetName() const
*/

/*
regex_match(Email, Pattern) возвращает bool:
true - если вся строка Email полностью соответствует регулярному выражению Pattern
false - если строка не соответствует шаблону
*/

/*
throw std::invalid_argument:
Конкретный класс исключения, наследующий от logic_error
Специально предназначен для недопустимых аргументов функций
Когда использовать:
Когда передаваемый аргумент не соответствует ожидаемому формату или диапазону

exception - Базовый класс всех исключений:
Базовый класс для ВСЕХ стандартных исключений C++
invalid_argument, out_of_range, runtime_error и др. наследуются от него
& - ловим по ссылке (избегаем копирования)
const - не изменяем объект исключения
exception - ловим любые стандартные исключения

Иерархия исключений:
exception
├── logic_error
│   ├── invalid_argument ← ваш случай!
│   ├── out_of_range
│   └── ...
├── runtime_error
│   ├── overflow_error
│   └── ...
└── ...

Конкретный пример работы:
try {
  User user("John", 200, "john@email.com"); // Возраст 200 - недопустимый аргумент
} 
catch (const invalid_argument& e) {
  // Поймает ТОЛЬКО invalid_argument
  cout << "Invalid argument: " << e.what() << endl;
}
catch (const exception& e) {
  // Поймает ЛЮБОЕ стандартное исключение
  cout << "General error: " << e.what() << endl;
}

Почему именно такая структура:
Бросаем конкретное invalid_argument - ясная семантика ошибки
Ловим общее exception& - перехватываем любые непредвиденные ошибки
e.what() - метод, возвращающий строку с описанием ошибки
*/

// #include <iostream>
// #include <string>
// #include <regex> // Регулярное выражение
// #include <stdexcept>
// using namespace std;

// class User {
//   private:
//     string Name;
//     int32_t Age;
//     string Email;

//     bool IsValidEmail(const string& Email) {
//       const regex Pattern(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
//       return regex_match(Email, Pattern);
//     } 

//   public:
//     User(const string& N, int32_t A, const string& E) {
//       SetName(N);
//       SetAge(A);
//       SetEmail(E);
//     }

//     void SetName (const string& NewName) {
//       if(NewName.empty()) {
//         throw invalid_argument("The Name cannot be empty. ");
//       }
//       if(NewName.length() > 50) {
//         throw invalid_argument("The name is too long (max. 50 characters)");
//       }
//       Name = NewName;
//     }

//     void SetAge(int32_t NewAge) {
//       if(NewAge < 0 || NewAge > 150) {
//         throw invalid_argument("The age must be between 0 and 150 years old.");
//       }
//       Age = NewAge;
//     }

//     void SetEmail(const string& NewEmail) {
//       if(NewEmail.empty()) {
//         throw invalid_argument("An email cannot be empty");
//       }
//       if(!IsValidEmail(NewEmail)) {
//         throw invalid_argument("Incorrect email format");
//       }
//       Email = NewEmail;
//     }

//     string GetName() const { return Name; };
//     int32_t GetAge() const { return Age; }
//     string GetEmail() const { return Email; }

//     void PrintInfo() const {
//       cout << "Users: " << Name << ", " << Age << " years old, " 
//       << "email: " << Email << endl;
//     }
// };

// int main() {

// try {
//   User MyUser("Danya", 27, "dkaalinkov@yandex.ru");
//   MyUser.PrintInfo();

//   // Пробуем установить некорректные значения:
//   MyUser.SetAge(300);
//   MyUser.PrintInfo();
// } catch (const exception& e) {
//   cout << "Error: " << e.what() << endl;
// }

// try {
//   User MyUser2("", 27, "dkaalinkov@yandex.ru");
// } catch (const exception& e) {
//   cout << "Error when creating: " << e.what() << endl;
// }

//   return 0;
// }

// Логирование в Getter'ах и Setter'ах (Класс BankAccount, где все операции логируются):

// #include <iostream>
// #include <string>
// #include <chrono>
// #include <iomanip> // std::put_time

// class BankAccount {
//   private:  
//     std::string AccountNumber;
//     double Balance;
//     std::string Owner;

//     void Log(const std::string& Action, const std::string& Details = "") const {
//       auto Now = std::chrono::system_clock::now();
//       auto time = std::chrono::system_clock::to_time_t(Now); // auto = time_t

//       std::cout << "[" << std::put_time(localtime(&time), "%Y-%m-%d %H:%M:%S") << "] "
//            << "Account " << AccountNumber << " - " << Action;
//       if (!Details.empty()) {
//           std::cout << " - " << Details;
//       }
//       std::cout << std::endl;
//     }
  
//   public:
//     BankAccount(const std::string& AccNumber, const std::string& OwnerName, 
//                 double InitialBalance) 
//                 : AccountNumber(AccNumber), Balance(InitialBalance), Owner(OwnerName) {
//                   Log("Account created", "Balance: " + std::to_string(InitialBalance));
//                 }

//     void SetBalance(double NewBalance) {
//       if (NewBalance < 0) {
//         Log("Balance setting error", "negative value: " + std::to_string(NewBalance));
//         throw std::invalid_argument("The balance cannot be negative");
//       }

//       double OldBalance = Balance;
//       Balance = NewBalance;

//       Log("Balance changed",
//           "Old value: " + std::to_string(OldBalance) + 
//           ", New value: " + std::to_string(NewBalance));
//     }

//     double GetBalance() const {
//       Log("Balance request");
//       std::cout << "Current balance: ";
//       return Balance;
//     }

//     std::string GetAccountNumber() const {
//       Log("Account number request", "WARNING: confidential data");
//       std::cout << "Account number: ";
//       return AccountNumber;
//     }

//     void SetOwner(const std::string& NewOwner) {
//       std::string OldOwner = Owner;
//       Owner = NewOwner;
//       Log("Change of ownership",
//           "Old ownership: " + OldOwner + 
//           ", New ownership: " + NewOwner);
//     }

//     std::string GetOwner() const {
//       Log("Requesting information about the owner");
//       std::cout << "Account owner: ";
//       return Owner;
//     }

//     ~BankAccount() {
//       Log("Account closed", "Final balance: " + std::to_string(Balance));
//     }
// };

// int main() {

// BankAccount Account("2134567890", "Daniil Kalinkov", 1000.0);

// std::cout << Account.GetOwner() << std::endl;

// std::cout << Account.GetBalance() << std::endl;

// try {
// Account.SetBalance(1500.0);
// } catch (const std::exception& e) {
//   std::cout << "Error: " << e.what() << std::endl;
// }
// std::cout << Account.GetBalance() << std::endl;

// try {
//   Account.SetBalance(-1000.00);
// } catch (const std::exception& e) {
//   std::cout << "Error: " << e.what() << std::endl;
// }

// std::cout << Account.GetAccountNumber() << std::endl;

//   return 0;
// }

// Совместное использование валидации и логирования:

// #include <iostream>
// #include <string>
// #include <regex>
// // #include <stdexcept>
// #include <chrono>
// #include <iomanip>

// class User {
//   private:
//     std::string Name;
//     std::string Email;
//     int32_t Age;

//     bool IsValidEmail(const std::string& Email) {
//       const std::regex Pattern(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
//       return std::regex_match(Email, Pattern);
//     }

//     void Log(const std::string& Action, const std::string& Details = "") const {
//       auto Now = std::chrono::system_clock::now();
//       auto Time = std::chrono::system_clock::to_time_t(Now);

//       std::cout << "[" << std::put_time(localtime(&Time), "%Y-%m-%d %H:%M:%S") << "] "
//                 << "Action: " << Action;
//       if(!Details.empty()) { std::cout << ", Details operation: " << Details; }
//       std::cout << std::endl;
//     }

//   public: 
//     User(std::string N, std::string E, int32_t A) {
//       SetName(N);
//       SetEmail(E);
//       SetAge(A);
//       Log("Calling the constructor");
//     }

//     void SetName(std::string NewName) {
//       if (NewName.empty()) {
//         Log("Calling the SetName function with Error");
//         throw std::invalid_argument("The name cannot be empty\n");
//       }
//       if (NewName.length() > 50) {
//         Log("Calling the SetName function with Error");
//         throw std::invalid_argument("The name is too long (max. 50 characters)\n");
//       }
//       Name = NewName;
//       Log("Calling the function SetName", "changing the name to " + NewName);
//     }

//     void SetEmail(std::string NewEmail) {
//       if (!IsValidEmail(NewEmail)) {
//         Log("Calling the SetEmail function with an Error");
//         throw std::invalid_argument("Incorrect email format\n");
//       }
//       if (NewEmail.empty()) {
//         Log("Calling the SetEmail function with an Error");
//         throw std::invalid_argument("The email cannot be empty\n");
//       }
//       Email = NewEmail;
//       Log("Calling the function SetEmail", "changing the email to " + NewEmail);
//     }

//     void SetAge(int32_t NewAge) {
//       if (NewAge < 0 || NewAge > 150) {
//         Log("Calling the SetAge function with Error");
//         throw std::invalid_argument("Incorrect Age. (The available range is from 0 to 150\n");
//       }
//       Age = NewAge;
//       Log("Calling the function SetAge", "changing the age to " + std::to_string(NewAge));
//     }

//     void PrintInfoUser() {
//       Log("Calling the function PrintInfoUser");
//       std::cout << "Info about user: \n" << "Username: " << Name << ", user's email: " << Email 
//                 << ", user's age" << Age << std::endl;
//     }

//     std::string GetName() {
//       Log("Calling the function GetName"); 
//       std::cout <<  "Name owner: ";
//       return Name;}
//     std::string GetEmail() {
//       Log("Calling the function GetEmail"); 
//       std::cout << "Email: ";
//       return Email;}
//     int32_t GetAge() {
//       Log("Calling the function GetAge"); 
//       std::cout << "Age: ";
//       return Age;}
// };

// int main() {

// User MyUser("Danya", "dkaalinkov@uandex.ru", 27);

// try {
//   MyUser.SetName("");
//   std::cout << MyUser.GetName() << std::endl;
// } catch (const std::exception& e) {
//   std::cout << "Error: " << e.what() << std::endl;
// }

// try {
// MyUser.SetName("Borya");
// std::cout << MyUser.GetName() << std::endl;
// } catch (const std::exception& e) {
//   std::cout << "Error: " <<e.what() << std::endl;
// }

// try {
// MyUser.SetEmail("dkkalinkov@yandex.ru");
// std::cout << MyUser.GetEmail() << std::endl;
// } catch (const std::exception& e) {
//   std::cout << "Error: " << e.what() << std::endl;
// }

// try {
// MyUser.SetAge(160);
// std::cout << MyUser.GetAge() << std::endl;
// } catch (const std::exception& e) {
//   std::cout << "Error: " << e.what() << std::endl;
// }

//   return 0;
// }

// Комбинированный пример: Валидация + Логирование + Кэширование:

/*
std::string getFormattedReport() const - Getter с кэшированием результата

strftime(TimeStr, sizeof(TimeStr), "%Y-%m-%d %H:%M:%S", localtime(&LastUpdateTime)); - 
Эта строка выполняет форматирование времени - преобразует сырое 
количество секунд в красивую читаемую дату и время.

localtime() - функция, которая преобразует time_t в структуру tm с полями:
tm_year (год с 1900)
tm_mon (месяц 0-11)
tm_mday (день месяца 1-31)
tm_hour (часы 0-23)
tm_min (минуты 0-59)
tm_sec (секунды 0-59)

"%Y-%m-%d %H:%M:%S" - строка формата:
%Y - год с веком (2024)
%m - месяц с ведущим нулем (01-12)
%d - день месяца с ведущим нулем (01-31)
%H - час в 24-часовом формате (00-23)
%M - минуты с ведущим нулем (00-59)
%S - секунды с ведущим нулем (00-59)

TimeStr[20] - буфер (массив символов), куда будет записан результат
sizeof(TimeStr) - размер буфера (20 символов)

strftime() - главная функция
Функция принимает все вышеперечисленное и формирует строку
strftime(буфер, размер_буфера, формат, структура_времени);
*/

// #include <iostream>
// #include <string>
// #include <ctime> // time(), strftime, localtime

// class WeatherSensor {
//   private:
//     double Temperature;
//     int32_t Humidity;
//     time_t LastUpdateTime;
//     mutable std::string LastFormattedReport; // mutable - можно изменять в const-методах
//     mutable bool IsReportCached = false;

//     void ValidateTemperature(double Temp) const {
//       if (Temp < -100.0 || Temp > 100.0) {
//         throw std::out_of_range("The temperature is outside the acceptable range");
//       }
//     }
    
//     void ValidateHumidity(int32_t Hum) const {
//       if (Hum < 0 || Hum > 100) {
//         throw std::out_of_range("Humidity should be between 0% and 100%");
//       }
//     }

//     void LogUpdate(const std::string& Parameter, double OldValue, double NewValue) const {
//       std::cout << "[LOG] " << Parameter << " changed: " << OldValue 
//               << " -> " << NewValue << std::endl;
//     }

//     public:
//       WeatherSensor() : Temperature(0.0), Humidity(0), LastUpdateTime(time(0)) {}

//       void SetTemperature(double NewTemperature) {
//         ValidateTemperature(NewTemperature);
//         double OldTemperature = Temperature;
//         Temperature = NewTemperature;
//         LastUpdateTime = time(0);
//         IsReportCached = false; // Сбрасываем кэш при изменении данных
//         LogUpdate("Tempreture", OldTemperature, NewTemperature);
//       }

//       void SetHumidity(int32_t NewHumidity) {
//         ValidateHumidity(NewHumidity);
//         int32_t OldHumidity = Humidity;
//         Humidity = NewHumidity;
//         LastUpdateTime = time(0);
//         IsReportCached = false;
//         LogUpdate("Humidity", OldHumidity, NewHumidity);
//       }

//       std::string GetFormattedReport() const {
//         if (!IsReportCached) {
//           std::cout << "[LOG] Report generation (cache updated)" << std::endl;
//           char TimeStr[20];
//           strftime(TimeStr, sizeof(TimeStr), "%Y-%m-%d %H:%M:%S", localtime(&LastUpdateTime));

//           LastFormattedReport = "Time: " + std::string(TimeStr) +
//                                 ", Temperature: " + std::to_string(Temperature) +
//                                 "°C, Humidity: " + std::to_string(Humidity) + "%";
          
//           IsReportCached = true;
//         } else {
//           std::cout << "[LOG] returning a report from the cache" << std::endl;
//         }

//         return LastFormattedReport;
//       }

//       double GetTemperature() const { return Temperature; }
//       int32_t GetHumidity() const { return Humidity; }
// };

// int main() {

// WeatherSensor Sensor;

// try {
// Sensor.SetTemperature(25.5);
// } catch (const std::exception& e) {
//   std::cout << "Error: " << e.what() << std::endl;
// }

// try {
// Sensor.SetHumidity(60);
// } catch (const std::exception& e)  {
//   std::cout << "Error: " << e.what() << std::endl;
// }

// std::cout << Sensor.GetFormattedReport() << std::endl << std::endl;

//   return 0;
// }

//остановился

//-----------------------------------------------------private, protected, public:

/*
Отличный вопрос! Переменные класса Car не перезаписываются, 
потому что объекты Vesta и BMW - это разные объекты в памяти.
Память программы:
│
├── Объект Vesta (тип Car)
│   ├── SpeedCar = 260
│   └── WeightCar = 2500.00
│
├── Объект BMW (тип Bike)  
│   ├── Базовая часть Car
│   │   ├── SpeedCar = 270    ← Свои собственные значения!
│   │   └── WeightCar = 2600.00 ← Свои собственные значения!
│   └── Производная часть Bike
│

Ключевой момент:
Наследование ≠ общие переменные
Наследование означает, что Bike получает копию структуры Car
Но каждый объект Bike имеет свои собственные, независимые поля Car
Изменение полей в одном объекте не влияет на другие объекты
Это фундаментальный принцип ООП: инкапсуляция и независимость объектов!
*/

// #include <iostream>
// using namespace std;

// class Car {
//   protected:
//     int32_t SpeedCar;
//     double WeightCar;
//   public:
//     Car(int32_t S, double W) : SpeedCar(S), WeightCar(W) {}

//     void PrintInfoCar() {
//       cout << "Car speed: " << SpeedCar << ", Car weight: " << WeightCar << endl;
//     }

//     void ShowAddressVesta() {
//       cout << "Address of Vesta.SpeedCar:" << &SpeedCar << endl;
//     }
// };

// class Bike : public Car {
//   public: 
//     Bike(int32_t R, double T) : Car(R, T) {}

//     void PrintInfoBike() {
//       cout << "Bike speed: " << SpeedCar << ", Bike weight: " << WeightCar << endl; 
//     }

//     void ShowAddressBMW() {
//       cout << "Address of Bike.SpeedCar: " << &SpeedCar << endl;
//     }
// };

// int main() {

// Car Vesta(260, 2500.00);
// Vesta.PrintInfoCar();

// Bike BMW(270, 2600.00);
// BMW.PrintInfoBike();
// Vesta.PrintInfoCar();

// // Адреса в памяти:
// Vesta.ShowAddressVesta();
// BMW.ShowAddressBMW(); // <- different addresses

//   return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// class Vehicle {
//   protected:
//     int32_t Speed;
//   public:
//     Vehicle(int32_t S) : Speed(S) {}

//     virtual void Func() = 0;

//     virtual int32_t GetSpeed() = 0;
// };

// class Car : public Vehicle {
//   private:
//     string ModelCar;
//   public:
//     Car(int32_t S, string M) : Vehicle(S), ModelCar(M){}

//     void Func() override { cout << "Car model is " << ModelCar << endl; }

//     int32_t GetSpeedCar() { return Speed; }

//     string GetModelCar() { return ModelCar; }

//     int32_t GetSpeed() override { return Speed; }
// };

// class Bike : public Vehicle {
//   private:  
//     string ModelBike;
//   public:
//     Bike(int32_t S, string M) : Vehicle(S), ModelBike(M) {}

//     void Func() override { cout << "Bike model is " << ModelBike << endl; }

//     int32_t GetSpeedBike() { return Speed; }

//     string GetModelBike() { return ModelBike; }

//     int32_t GetSpeed() override { return Speed; }
// };

// int main() {

// Vehicle* MyVehicle[2];
// MyVehicle[0] = new Car(250, "Vesta");
// MyVehicle[1] = new Bike(260, "BMW");

// MyVehicle[0]->Func();
// MyVehicle[1]->Func();

// Car MyCar(270, "Vesta2");
// cout << MyCar.GetModelCar() << endl;
// cout << MyCar.GetSpeedCar() << endl;

// Bike MyBike(280, "BMW2");
// cout << MyBike.GetModelBike() << endl;
// cout << MyBike.GetSpeedBike() << endl;

// cout << MyCar.GetSpeedCar() << endl;

// cout << MyVehicle[0]->GetSpeed() << endl;

//   return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// class BankAccount {
//   private:
//     string OwnerName;
//     double Balance;

//     void LogTransaction(const string& Message) {
//       cout << "[LOG] " << Message << ". New balance: " << Balance << endl;
//     }
//   public: 
//     BankAccount(const string& Name, double InstalBalance) 
//       : OwnerName(Name), Balance(InstalBalance) {}

//     void Deposit(double Amount) {
//       if(Amount > 0) {
//         Balance += Amount;
//         LogTransaction("Deposited " + to_string(Amount));
//       }
//     }

//     bool Withdraw(double Amount) {
//       if(Amount > 0 && Balance >= Amount) {
//         Balance -= Amount;
//         LogTransaction("Withdrew " + to_string(Amount));
//         return true;
//       }
//       cout << "Withdrawal failed!" << endl;
//       return false;
//     }

//     string GetOwnerName() const {
//       return OwnerName;
//     }

//     double GetBalance() const {
//       return Balance;
//     }

//     void SetOwnerName(const string& NewName) {
//       if(!NewName.empty()) {
//         OwnerName = NewName;
//       }
//     }    
// };

// int main() {

// BankAccount Account("Borya", 1000.0);

// cout << Account.GetOwnerName() << endl;
// Account.Deposit(500.0);
// Account.Withdraw(200.0);
// cout << "Balance: " << Account.GetBalance() << endl;

// Account.SetOwnerName("Danya");
// cout << Account.GetOwnerName() << endl;


//   return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// class Vehicle {
//   protected:
//     int32_t MaxSpeed;
//     string Model;
  
//     void DisplaySpecs() const {
//       cout << "Model: " << Model << ", Max Speed: " << MaxSpeed << " km/h" << endl;
//     }

//   public:
//     Vehicle(int32_t Speed, const string& M) : MaxSpeed(Speed), Model(M) {}
//     virtual ~Vehicle() = default;

//     void Start() const {
//       cout << Model << " is starting..." << endl;
//     }
// };

// class Car : public Vehicle {
//   private:
//     int32_t NumDoors;
//   public:
//     Car(int32_t Speed, const string& M, int32_t Doors) : Vehicle(Speed, M), NumDoors(Doors) {}

//     void ShowInfo() const {
//       cout << "This is a car. ";
//       DisplaySpecs();
//       cout << "Doors: " << NumDoors << endl;
//     }

//     void UpgradeEngine(int32_t NewPower) {
//       MaxSpeed += NewPower;
//       cout << Model << " has been upgraded! New max speed: " << MaxSpeed << " km/h" << endl;
//     }
// };

// int main() {

// Car MyCar(256, "Vesta", 4);
// MyCar.Start();
// MyCar.ShowInfo();

// MyCar.UpgradeEngine(50);

//   return 0;
// }

// Сравнение трех модификаторов:

// #include <iostream>
// using namespace std;

// class Base {
//   public:
//     int32_t PublicVar = 1;

//     void PublicFunc() { cout << "Public function" << endl; }

//   protected:
//     int32_t ProtectedVar = 2;

//     void ProtectedFunc() { cout << "Protected function" << endl; }

//   private:
//     int32_t PrivateVar = 3;

//     void PrivateFunc() { cout << "Private function" << endl; }

//   public:
//     void TestAccess() {
//       PublicVar = 10;
//       ProtectedVar = 20;
//       PrivateVar = 30;
//       PublicFunc();
//       ProtectedFunc();
//       PrivateFunc();
//     }
// };

// class Derived : public Base {
//   public:
//     void TestDerivedAccess() {
//       PublicVar = 100;
//       ProtectedVar = 200;

//       PublicFunc();
//       ProtectedFunc();
//     }
// };

// int main() {

// Base MyBase;

// MyBase.PublicFunc();
// MyBase.TestAccess();
// MyBase.PublicVar = 1000;

// cout << MyBase.PublicVar << endl;

//   return 0;
// }

// #include <iostream>

// class Base {
// public:
//     int publicVar = 1;
//     void publicFunc() { std::cout << "Public function" << std::endl; }

// protected:
//     int protectedVar = 2;
//     void protectedFunc() { std::cout << "Protected function" << std::endl; }

// private:
//     int privateVar = 3;
//     void privateFunc() { std::cout << "Private function" << std::endl; }
// };

// // Public наследование - наиболее распространенное
// class DerivedPublic : public Base {
// public:
//     void test() {
//         publicVar = 10;      // OK: public остается public
//         protectedVar = 20;   // OK: protected остается protected
//         // privateVar = 30;  // Ошибка: private недоступно
        
//         publicFunc();        // OK
//         protectedFunc();     // OK
//         // privateFunc();    // Ошибка
//     }
// };

// // Protected наследование - используется редко
// class DerivedProtected : protected Base {
// public:
//     void test() {
//         publicVar = 10;      // OK: public становится protected
//         protectedVar = 20;   // OK: protected остается protected
        
//         publicFunc();        // OK
//         protectedFunc();     // OK
//     }
// };

// // Private наследование - реализация "на основе"
// class DerivedPrivate : private Base {
// public:
//     void test() {
//         publicVar = 10;      // OK: public становится private
//         protectedVar = 20;   // OK: protected становится private
        
//         publicFunc();        // OK
//         protectedFunc();     // OK
//     }
// };

// int main() {
//     DerivedPublic dp;
//     dp.publicFunc();     // OK: public наследование
//     // dp.protectedFunc(); // Ошибка: protected недоступен извне
    
//     DerivedProtected dprot;
//     // dprot.publicFunc(); // Ошибка: public стал protected
    
//     DerivedPrivate dpriv;
//     // dpriv.publicFunc(); // Ошибка: public стал private
    
//     return 0;
// }

// Slicing (срезка) объектов:  

/*
Почему это плохо:

Потеря данных - часть Derived отрезается
Потеря полиморфизма - вызываются методы Base, а не Derived
Неявная ошибка - компилятор не предупреждает

Как избежать:

Использовать указатели или ссылки на базовый класс
Использовать умные указатели: std::unique_ptr<Base>, std::shared_ptr<Base>
*/

// #include <iostream>

// class Base {
//   public:
//     int32_t BaseData = 10;
//     virtual void Print() const {
//       std::cout << "Base: " << BaseData << std::endl;
//     }
// };

// class Derived : public Base {
//   public:
//     int32_t DerivedData = 20;
//     void Print() const override {
//       std::cout << "Derived: " << BaseData << ", " << DerivedData << std::endl;
//     }
// };

// void DemonstrateSlicing() {
//   Derived MyDerived;
//   MyDerived.DerivedData = 999;

//   // СЛОМАННЫЙ КОД - slicing!:
//   Base BaseObj = MyDerived; // Происходит срезка!
//   BaseObj.Print(); // Выведет: Base: 10

//   // Правильный подход - через указатель:
//   Base* BasePtr = &MyDerived;
//   BasePtr->Print(); // Выведет: Derived: 10, 999

//   // Или через ссылку:
//   Base& BaseRef = MyDerived;
//   BaseRef.Print(); // Выведет: Derived: 10, 999
// }

// int main() {

// DemonstrateSlicing();

//   return 0;
// }

//-----------------------------------------------------Указатели и ссылки:
/*Ссылка — это альтернативное имя (псевдоним) для существующей переменной. 
Она не хранит свой собственный адрес в памяти, а просто ссылается на ту же область памяти, 
что и исходная переменная.
Ключевые свойства ссылок:
Должны быть инициализированы при объявлении (не могут быть "пустыми").
Не могут быть перенаправлены на другую переменную после инициализации.
Работают как псевдоним — все операции с ссылкой влияют на исходную переменную.
Синтаксически выглядят как обычные переменные (не требуют оператора * для доступа).
Невозможно (int& ref = NULL; — ошибка)
Ограничения ссылок:
Нельзя создать массив ссылок.
Нет "ссылки на ссылку" (в отличие от указателей).
Не поддерживают арифметику (как указатели ptr++).
Ссылки vs Указатели: когда что использовать?
Ссылки:
Когда нужно работать с переменной "как есть" без риска nullptr.
Для передачи параметров в функции (особенно больших объектов).
Указатели:
Когда нужна динамическая память (new, delete).
Если требуется перенаправление на другой объект.

Ключевые моменты по указателям:
Указатель - это переменная, хранящая адрес другой переменной
Оператор & - получает адрес переменной
Оператор * (при работе с указателями):
В объявлении: int* a - создаёт указатель на int
В выражениях: *a - разыменовывает указатель (получает значение по адресу)
*/

// #include <iostream>

// int main() {

// long long variable = 20;

// long long* Ptr_variable = &variable; // Создаётся указатель Ptr_variable на тип long long. Оператор & берёт адрес переменной variable, и этот адрес сохраняется в указателе.
// *Ptr_variable = 30;
// std::cout << *Ptr_variable << std::endl; // *Ptr_variable — это разыменование указателя (получение значения, на которое он указывает).
// std::cout << &Ptr_variable << std::endl; // Выводится адрес самого указателя
// std::cout << Ptr_variable << std::endl; // Выводится адрес самой переменной (т.е. значение указателя Ptr_variable)

// long long& Ref_variable = variable; // long long& — объявление ссылки на тип long long. Ref_variable — имя ссылки. = variable — ссылка связывается с переменной variable.
// Ref_variable = 31;
// std::cout << Ref_variable << std::endl; // Ссылка не требует разыменования (в отличие от указателя), она работает как обычная переменная.
// std::cout << &Ref_variable << std::endl; // Выводит адрес переменной Variable

//   return 0;
// }

// #include <iostream>

// void PlusOne(int* a);
// void PlusTwo(int& a);

// int main() {

// int Variable = 105;
// PlusOne(&Variable);
// std::cout << Variable << std::endl;

// PlusTwo(Variable);
// std::cout << Variable << std::endl;

//   return 0;
// }

// void PlusOne(int* a) {
//   *a += 1;
// }

// void PlusTwo(int& a) {
//   a += 2;
// }

// Примеры с указателями:

// #include <iostream>

// void Swap(int* a, int* b);
// void Swap(int& a, int& b);

// int main() {

// int Variable1 = 5;
// int Variable2 = 6;

// std::cout << Variable1 << ", " << Variable2 << std::endl;

// Swap(&Variable1, &Variable2);
// std::cout << Variable1 << ", " << Variable2 << std::endl;

// Swap(Variable1, Variable2);
// std::cout << Variable1 << ", " << Variable2 << std::endl;

//   return 0;
// }

// void Swap(int* a, int* b) {
//   int Temp = *a;
//   *a = *b;
//   *b = Temp;
// }

// void Swap(int& a, int& b) {
//   int Temp = a;
//   a = b;
//   b = Temp;
// }

/*
int* ptr = array: В C++ имя массива уже является указателем на первый элемент этого массива,
поэтому мы фактически присваиваем указателю ptr адрес первого элемента массива array. Это эквивалентно: int* ptr = &array[0];
*/

// #include <iostream>

// int main() {

// int Array[6] = {1, 34, 6, 61, -1, 7};
// int SizeBytes = sizeof(Array);
// int SizeArray = SizeBytes / sizeof(Array[0]);
// int* Ptr = Array;

// for(int i = 0; i < 6; i++) {
//   std::cout << "Array[" << i << "] = " << *(Ptr + i); 
//   if (i < SizeArray - 1) {
//     std::cout << ", ";
//   } else {
//     std::cout << ".";
//   }
//   std::cout << std::endl;
// }

//   return 0;
// }

// #include <iostream>

// using namespace std;

// int main() {

// int SizeArray;
// cout << "Enter array size: ";
// cin >> SizeArray;
// int* Array = new int[SizeArray]; // динамическое выделение памяти под массив целых чисел (int) размером size

// for(int i = 0; i < SizeArray; i++) {
//   Array[i] = i * 1;
//   cout << *(Array + i);
//   if(i < SizeArray - 1) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
// }
// cout << endl;

// delete[] Array;

//   return 0;
// }

// Указатель на функцию

/*
Представьте, что func — это пульт дистанционного управления, 
который можно настроить на вызов разных функций (add или sub).

add — это имя функции, но без скобок оно представляет собой указатель 
на функцию (как массив без индекса — указатель на его начало).
Теперь operation хранит адрес add и может вызывать её.
*/

// #include <iostream>

// using namespace std;

// int Addition(int a, int b);
// int Subtraction(int a, int b);

// int main() {

// int (*Function) (int, int);

// Function = Addition;

// cout << Function(34, 78) << endl;

// Function = Subtraction;

// cout << Function(45, 9) << endl;

//   return 0;
// }

// int Addition(int a, int b) {
//   return a + b;
// }

// int Subtraction(int a, int b) {
//   return a - b;
// }

// #include <iostream>

// using namespace std;

// void PlusOne(int* a);
// void PlusTwo(int& a);

// int main() {

// int Variable = 119;

// void (*Function) (int*);
// Function = PlusOne;
// Function(&Variable);

// cout << Variable << endl;

// void (*FunctionRef) (int&);
// FunctionRef = PlusTwo;
// FunctionRef(Variable);

// cout << Variable << endl;

//   return 0;
// }

// void PlusOne(int* a) {
//   *a += 1;
// }

// void PlusTwo(int& a) {
//   a += 2;
// }

// Доделать
// Многоуровневые указатели и динамические структуры данных
// #include <iostream>

// struct node {
//   int data;
//   node* next;
// };

// void append(node** head_ref, int new_data);

// int main () {



//   return 0;
// }

// void append(node** head_ref, int new_data) {

// }

// Указатели на члены класса:

/*
Создаем указатель на член класса myclass типа int с именем ptr_value 
и инициализируем его адресом поля value класса myclass.
*/

/*
void (myclass::*ptr_print)() = &myclass::print; - 
Создаем указатель на метод класса myclass с именем ptr_print, 
который может указывать на методы без параметров, возвращающие void, 
и инициализируем его адресом метода print.
*/

/*
PtrVariable — указатель, который может ссылаться на поле int в классе Myclass.
&Myclass::Variable — берётся адрес поля Variable внутри класса (не путать с адресом конкретного объекта!)
*/

// #include <iostream>

// using namespace std;

// class Myclass {
//   public:
//     int Variable; // Член-данные класса- целочисленная переменная value

//     Myclass(int V) : Variable(V) {}

//     void Prinf() {cout << Variable << endl;} // Член-функция класса
// };

// int main() {

// Myclass Obj(10);

// // Указатель на член-данные (value):
// int Myclass::*PtrVariable = &Myclass::Variable;
// cout << Obj.*PtrVariable << endl;

// // Указатель на член-функцию (print()):
// void (Myclass::*PtrPrint)() = &Myclass::Prinf;
// (Obj.*PtrPrint)();

//   return 0;
// }

//-----------------------------------------------------Умные указатели:

// Основные типы умных указателей в C++:

// std::unique_ptr:

/*
Указатель с исключительным владением. Не может быть скопирован, но может быть перемещен. 
Удаляет объект при выходе из области видимости.

Деструктор unique_ptr вызывается при выходе из области видимости (в данном случае — 
при закрытии }), что гарантирует отсутствие утечек памяти. (вложенный блок)

Закрывающая скобка } относящаяся к вложенному блоку внутри main(), 
обязательна для корректной работы умных указателей. 
Она определяет момент, когда ptr2 (и, следовательно, объект MyClass) 
должен быть автоматически уничтожен.

Хорошие практики:
Используйте std::make_unique и std::make_shared вместо new
Используйте unique_ptr по умолчанию, если не нужны разделяемые указатели.
Используйте shared_ptr только когда действительно необходимо разделяемое владение.
Используйте weak_ptr для разрыва циклических зависимостей между shared_ptr.
Не смешивайте сырые указатели с умными, если это возможно.
*/

// #include <iostream>
// #include <memory>

// using namespace std;

// class MyClass {
//   public:
//     MyClass() { cout << "MyClass constructed\n"; }
//     ~MyClass() { cout << "MyClass destroyed\n"; }

//     void DoSomething() { cout << "Do Something\n"; }
// };

// int main() {

//   { // <- Начало вложенного блока (создан для демонстрации работы std::unique_ptr)
//     // unique_ptr<MyClass> Ptr1 = make_unique<MyClass>();
//     unique_ptr<MyClass> Ptr1 (new MyClass());
//     Ptr1->DoSomething();

//     // Можно передать владение:
//     unique_ptr<MyClass> Ptr2 = move(Ptr1);

//     if(Ptr1 == nullptr) {
//       cout << "Ptr is now empty\n";
// }
//   } // <- Конец вложенного блока

//   return 0;
// }

// std::shared_ptr:

/*
Указатель с разделяемым владением. Подсчитывает количество ссылок на 
объект и удаляет его, когда счетчик достигает нуля.
*/

// #include <iostream>
// #include <memory>

// using namespace std;

// class MyClass {
//   public: 
//     MyClass() { cout << "MyClass constructed\n"; }
//     ~MyClass() { cout << "MyClass destroyed\n"; }
    
//     void DoSomething() {
//       cout << "Doing something\n";
//     }
// };

// int main() {

// // ptr1 изначально пуст (use_count = 0):
// shared_ptr<MyClass> ptr1;
// cout << "After declaration, ptr use count: " << ptr1.use_count() << endl;

// {
//   shared_ptr<MyClass> ptr2 = make_shared<MyClass>();
//   ptr2->DoSomething();
//   cout << "After declaration, ptr use count: " << ptr2.use_count() << endl;

//   // Присваиваем ptr1 = ptr2 - теперь оба владеют объектом:
//   ptr1 = ptr2;
//   cout << "After declaration, ptr use count: " << ptr1.use_count() << endl;
//   cout << "After declaration, ptr use count: " << ptr2.use_count() << endl;
// } // <- ptr2 выходит из области видимости, но объект не удаляется, так как ptr1 все еще держит ссылку

// cout << "Now only ptr1 remains, use count: " << ptr1.use_count() << endl;
// // cout << "Now only ptr1 remains, use count: " << ptr2.use_count() << endl; - ptr2 уже не сработает 
// ptr1->DoSomething();

//   return 0;
// } // <- ptr1 выходит из области видимости, счетчик ссылок достигает 0, объект удаляется, вызывается деструктор MyClass

// std::weak_ptr:

/*
Слабая ссылка на объект, управляемый shared_ptr. 
Не увеличивает счетчик ссылок. Полезен для разрыва циклических зависимостей.

// lock():
weak_ptr.lock() - создает временный shared_ptr из weak_ptr.
Если исходный объект еще существует, lock() вернет рабочий shared_ptr
Если объект уже удален, вернет "пустой" shared_ptr (который в условии if даст false).

// reset():
shared_ptr.reset() - уменьшает счетчик ссылок и освобождает владение объектом.

После reset():
- ptr1 перестает указывать на объект
- Счетчик ссылок на объект уменьшается на 1
- Если счетчик стал 0 → объект удаляется

Проблема циклической зависимости (как у нас в коде ниже):

ptr1->other = ptr2;  // ptr2 владеет объектом A
ptr2->other = ptr1;  // ptr1 владеет объектом B

// Теперь:
// A держит shared_ptr на B
// B держит shared_ptr на A

ptr1.reset();  // Счетчик для A: 1 (его держит B->other)
ptr2.reset();  // Счетчик для B: 1 (его держит A->other)

// Объекты не удаляются, хотя "внешних" ссылок нет!
// Это утечка памяти.

Ниже, после неверного кода, будет приведен пример правильного использооварния.
*/

// #include <iostream>
// #include <memory>

// using namespace std;

// class MyClass {
//   public:
//     shared_ptr<MyClass> Other; // Будет утечка
//     // weak_ptr<MyClass> Other; // Утечки не будет
//     ~MyClass() { cout << "MyClass destroyed\n"; }
// };

// int main() {

// shared_ptr<MyClass> ptr1 = make_shared<MyClass>();
// shared_ptr<MyClass> ptr2 = make_shared<MyClass>();

// cout << "Use count: " << ptr1.use_count() << endl;
// cout << "Use count: " << ptr2.use_count() << endl;

// ptr1->Other = ptr2;
// ptr2->Other = ptr1; // Циклическая зависимость

// weak_ptr<MyClass> weak = ptr1;
// cout << "Use count: " << ptr1.use_count() << endl;
// cout << "Use count: " << ptr2.use_count() << endl;
// cout << "Use count: " << weak.use_count() << endl;

// // Проверяем, жив ли еще объект:
// if(auto shared = weak.lock()) { // Создаем shared_ptr из weak_ptr
//   cout << "Object still exists\n";
//   // Здесь можно безопасно использовать shared
// } else {
//   cout << "Object already destroyed\n";
// }

// ptr1.reset(); // Эквивалентно ptr1 = nullptr;
// ptr2.reset(); // Объекты не удаляются из-за циклической зависимости

// // Решение: заменить один из shared_ptr на weak_ptr

//   return 0;
// }

// Пример правильного использования weak_ptr:

/*
weak_ptr не увеличивает счетчик ссылок.
Когда ptr1 и ptr2 сбрасываются, счетчики становятся 0 → объекты удаляются.

Ключевые выводы:
lock() — безопасное преобразование weak_ptr → shared_ptr.
reset() — освобождение владения объектом.
Циклические зависимости между shared_ptr приводят к утечкам памяти.
Решение — замена одного из shared_ptr на weak_ptr разрывает цикл.
*/

// #include <iostream>
// #include <memory>

// using namespace std;

// class MyClass {
//   public:
//     weak_ptr<MyClass> Other;
//     ~MyClass() { cout << "MyClass destroyed\n"; }
// };

// int main() {

// auto Ptr1 = make_shared<MyClass>(); // weak_ptr не увеличивает счетчик (weak_ptr<MyClass> Other;)
// auto Ptr2 = make_shared<MyClass>(); // weak_ptr не увеличивает счетчик (weak_ptr<MyClass> Other;)

// // Альтернативная запись:
// // shared_ptr<MyClass> Ptr1 = make_shared<MyClass>(); 
// // shared_ptr<MyClass> Ptr2 = make_shared<MyClass>();

// cout << "Ptr1 use count: " << Ptr1.use_count() << endl;
// cout << "Ptr2 use count: " << Ptr2.use_count() << endl;

// Ptr1->Other = Ptr2;
// Ptr2->Other = Ptr1;

// cout << "Ptr1 use count: " << Ptr1.use_count() << endl;
// cout << "Ptr2 use count: " << Ptr2.use_count() << endl;

// if(auto Shared = Ptr1->Other.lock()) {
//   cout << "ptr2 still exists via weak_ptr\n";
// }

// Ptr1.reset(); // Удаляем A (счетчик B остается 1)
// Ptr2.reset(); // Удаляем B

// // Теперь объекты корректно удаляются!

//   return 0;
// }

//-----------------------------------------------------Работа с памятью:

// #include <iostream>

// using namespace std;

// int main() {

// int* Ptr = new int[30];
// Ptr[0] = 20;
// Ptr[2] = 22;

// cout << *(Ptr) << ", " << *(Ptr + 2) << endl;

// delete[] Ptr;

//   return 0;
// }

// #include <iostream>

// int main() {

// // int* Ptr = new int(43);
// int* Ptr = new int;
// *Ptr = 43;
// std::cout << *Ptr << std::endl;
// delete Ptr;

//   return 0;
// }

// #include <iostream>

// using namespace std;

// int main() {

// int* PtrArray = new int[5] {1, 2, 3, 4, 5};
// // int* PtrArray = new int[5];

// // PtrArray[0] = 1;
// // PtrArray[1] = 2;
// // PtrArray[2] = 3;
// // PtrArray[3] = 4;
// // PtrArray[4] = 5;

// for(int i = 0; i < 5; i++) {
//   cout << "PtrArray[" << i << "] = " << PtrArray[i];
//   if(i < 5 - 1) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   cout << endl;
// }

// delete[] PtrArray;

//   return 0;
// }

// Доразобрать:
//-----------------------------------------------------argv, argc

/*argc (argument count) - целое число, количество переданных аргументов
argv (argument vector) - массив строк (C-строк, char*), содержащий сами аргументы*/

// #include <iostream>

// int main(int argc, char* argv[]) {

// std::cout << "Количество аргументов: " << argc << std::endl;

// for(int i = 0; i < argc; i++) {
//   std::cout << i << ": " << argv[i] << std::endl;
// }

//   return 0;
// }

/*atoi в C++ преобразует строку (C-style строку, т.е. массив символов, 
завершающийся нулевым символом \0) в целое число (int).*/

/*std::stoi - Для проверки того, что мы ввели два целых числе, а не символ*/
/*std::stoi — это функция в C++, которая преобразует строку (std::string) в целое число (int). 
Является более безопасной и удобной альтернативой старой C-функции atoi.*/

// #include <iostream>
// #include <string> // std::stoi
// #include <limits>
// // #include <cstdlib> // atoi

// int main(int argc, char* argv[]) {

// if(argc != 3) {
//   std::cerr << "Использование: " << argv[0] << " <число1> <число2>" << std::endl;
  
//   return 1;
// }

// try {
//   int a = std::stoi(argv[1]);
//   int b = std::stoi(argv[2]);

//   if ((b > 0 && a > std::numeric_limits<int>::max() - b) ||
//       (b < 0 && a < std::numeric_limits<int>::min() - b)) {
//         std::cerr << "Ошибка: переполнение при сложении." << std::endl;
//         return 1;
//       }

//   std::cout << "Сумма: " << (a + b) << std::endl;
// }
// catch (const std::exception& e) {
//   std::cerr << "Ошибка: введите два целых числа." << std::endl;
//   return 1;
// }

// // int a = atoi(argv[1]);
// // int b = atoi(argv[2]);

//   return 0;
// }

//-----------------------------------------------------STL

/*STL (Standard Template Library) - это мощная библиотека шаблонов в C++, 
предоставляющая набор готовых классов и функций для работы с контейнерами, 
алгоритмами, итераторами и функциональными объектами.

Основные компоненты STL

Контейнеры (Containers)
Хранят коллекции объектов. Бывают нескольких типов:

Последовательные контейнеры: #include <vector>, #include <list>, #include <deque>
*/

// vector:

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {

// vector<int> Vec = {1, -3, 5, -2, 2, 7, -9, 3};
// Vec.push_back(40);
// Vec.pop_back(); // Удаление последнего элемента;
// int SizeVec = Vec.size(), i = 1;
// for(int n : Vec) {
//   cout << n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// list:

// #include <iostream>
// #include <list> // Список - двусвязный список
// #include <string>

// using namespace std;

// int main() {

// list<string> Names = { "Danya", "Borya", "Vanya", "Diana" };
// Names.push_front("Artom");
// Names.pop_front();
// int SizeList = Names.size(), i = 1;
// for(string n : Names) {
//   cout << n;
//   if(i < SizeList) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// deque: 
/*
deque (Дек) - двусторонняя очередь ("double-ended queue") - это контейнер STL, 
который сочетает в себе особенности вектора и списка, предоставляя эффективные операции 
вставки и удаления с обоих концов.
*/

// #include <iostream>
// #include <deque>

// using namespace std;

// int main() {
  
// deque<double> DqVec = { 1.1, 4.2, -2.3, 5.3, 6.5, -1.1, 7.9 };
// DqVec.push_back(23.1);
// DqVec.pop_front();
// int SizeDequeVec = DqVec.size(), i = 1;
// for(double n : DqVec) {
//   cout << n;
//   if(i < SizeDequeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

// i = 1;
// deque<string> DqNames = { "Danya", "Borya", "Vanya", "Diana" };
// DqNames.push_front("Artom");
// DqNames.pop_front();
// int SizeDequeList = DqNames.size();
// for(string n : DqNames) {
//   cout << n;
//   if(i < SizeDequeList) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// Ассоциативные контейнеры: #include <set>, #include <map>

// set:

// Множество (set) - уникальные элементы (отсортированные):

// #include <iostream>
// #include <set>

// using namespace std;

// int main() {

// set<int> UniqueNums = {5, 5, 2, -2, -3, 6, -9, 10, 1 };
// int SizeUniqueNums = UniqueNums.size(), i = 1;
// for(int n : UniqueNums) {
//   cout << n;
//   if(i < SizeUniqueNums) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;

// }
// cout << "\n";

// i = 1;
// set<string> UniqueList = {"Danya", "Borya", "Diana", "Vanya"};
// int SizeUniqueList = UniqueList.size();
// for(string n : UniqueList) {
//   cout << n;
//   if(i < SizeUniqueList) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// map:

/*
Отображение (map) - пары ключ-значение (может быть только два параметра: ключ и значение):
std::map так же сортирует ключи в порядке возрастания (в данной случае в лексикографическом порядке)
*/

// #include <iostream>
// #include <map>
// #include <string>

// using namespace std;

// int main() {

// map<string, int> ValueKey = {
//   {"One", 1},
//   {"Two", 2},
//   {"Three", 3},
//   {"Four", 4},
//   {"Five", 5}
// };
// ValueKey["Six"] = 6;

// int SizeValueKey = ValueKey.size(), i = 1;

// for(const auto& n : ValueKey) {
//   cout << "Value: " << n.first << ", Key: " << n.second;
//   if(i < SizeValueKey) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   cout << endl;
//   i++;
// }

// cout << "\n";

// i = 1;
// for(const auto& [Value, Key] : ValueKey) {
//   cout << "Value: " << Value << ", Key: " << Key;
//   if(i < SizeValueKey) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   cout << endl;
//   i++;
// }

//   return 0;
// }

// Неупорядоченные ассоциативные контейнеры (C++11):

/*Заголовочные файлы <set>, <unordered_set>, <map> и <unordered_map> предоставляют различные 
контейнеры для хранения данных. Их основные отличия связаны с организацией данных и 
производительностью операций.*/

/* unordered_set использует хеш-таблицу для хранения данных, 
хранит только уникальные значения*/
// #include <unordered_map>
// #include <iostream>
// #include<string>

// int main() {

// // Хеш-отображение:
// std::unordered_map<int, std::string> um = {
//   {1, "one"},
//   {2, "two"}
// };
// for(const auto& n : um) {
//   std::cout << n.first << n.second << std::endl;
// }
// for(const auto& [num, word] : um) {
//   std::cout << num << word << std::endl;
// }

//   return 0;
// }

// Хеш-множество:

/*
unordered_set использует хеш-таблицу для хранения данных, 
хранит только уникальные значения
*/

// #include <iostream>
// #include <unordered_set>
// #include <string>

// using namespace std;

// int main() {

// unordered_set<int> UniqueNums = { 2, 5, -1, 4, 2, -5, -10, 11, 3 };
// int SizeUniqueNums = UniqueNums.size(), i = 1;
// for(const auto& n : UniqueNums) {
//   cout << n;
//   if(i < SizeUniqueNums) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

// i = 1;
// unordered_set<string> UniqueNames = { "Danya", "Borya", "Diana", "Vanya", "Danya" };
// int SizeUniqueNames = UniqueNames.size();
// for(const auto& n : UniqueNames) {
//   cout << n;
//   if(i < SizeUniqueNames) {
//     cout << ". ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// Хеш-отображение:

// #include <iostream>
// #include <unordered_map>
// #include <string>

// using namespace std;

// int main() {

// unordered_map<string, int> ValueKey = {
//   {"One", 1},
//   {"Two", 2},
//   {"Three", 3}
// };
// ValueKey["Four"] = 4;

// int SizeValueKey = ValueKey.size(), i = 1;
// for(const auto& n : ValueKey) {
//   cout << "Value: " << n.first << ", Key: " << n.second;
//   if(i < SizeValueKey) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   cout << "\n";
//   i++;
// }
// cout << "\n";

// i = 1;
// for(const auto& [Value, Key] : ValueKey) {
//   cout << "Value: " << Value << ", Key: " << Key;
//   if(i < SizeValueKey) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   cout << endl;
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// Алгоритмы (STL) (Более 100 алгоритмов для работы с контейнерами):

/*
#include <algorithm> // std::sort, std::find, std::binary_search, std::reverse, std::for_each, std::nth_element, std::partition, std::copy
#include <numeric> // std::accumulate 
v.begin() и v.end() — это итераторы, которые указывают на начало и конец контейнера (например, вектора v).
std::cout << *v.begin() << std::endl; // Чтобы получить значение, на которое он указывает, нужно его разыменовать (*)
*/

// Сортировка:

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {

// vector<int> Vec = { 4, 5, 3, 1, 2, 6, 7, 10, 9, 8 };
// int SizeVec = Vec.size(), i = 1;
// sort(Vec.begin(), Vec.end());

// for(auto n = Vec.begin(); n != Vec.end(); n++) {
//   cout << *n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// Поиск:

/*
std::find — если данные не отсортированы или нужно получить итератор.
std::binary_search — если данные отсортированы и нужен только факт наличия.
Алгоритм последовательно перебирает элементы от v.begin() до v.end() (не включая v.end()).
!!!! Перед выполнением бинарного поиска (binary_search), массив обязательно должен быть отсортирован.
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {

// // Поиск:
// vector<int> Vec = { 4, 5, 3, 1, 2, 6, 7, 10, 9, 8 };
// auto it = find(Vec.begin(), Vec.end(), 3);
// if(it == Vec.end()) {
//   cout << "Element not found" << endl;
// } else {
//   cout << "Element found: " << *it << endl;
// }

// cout << "\n";

// // Бинарный поиск:
// sort(Vec.begin(), Vec.end());
// int DesiredNumber = 4;
// bool Result = binary_search(Vec.begin(), Vec.end(), DesiredNumber);
// if(Result) {
//   cout << "Element " << DesiredNumber << " found (" << Result << ")" << endl;
// } else {
//   cout << "Element " << DesiredNumber << " not found (" << Result << ")" << endl;
// }

//   return 0;
// }

// std::lower_bound, std::upper_bound:

/*
это алгоритмы для работы с отсортированными диапазонами, 
которые позволяют находить позиции элементов с помощью бинарного поиска.

Если нужен итератор на найденный элемент в отсортированном диапазоне, 
лучше использовать std::lower_bound или std::upper_bound

std::lower_bound - показывает число >= заднного.
!!!! Использовать на отсортированных массивах

std::upped_bound - показывает число > заднного.
!!!! Использовать на отсортированных массивах
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {

// // lower_bound:
// vector<int> Vec = { 4, 5, 3, 1, 6, 7, 10, 9, 8 };
// sort(Vec.begin(), Vec.end());
// int DesiredNum = 2;
// auto Iterator = lower_bound(Vec.begin(), Vec.end(), DesiredNum);
// if(Iterator != Vec.end()) {
//   cout << "First element >= " << DesiredNum << " is " << *Iterator 
//        << ", at position " << distance(Vec.begin(), Iterator) << endl;
// } else {
//   cout << "Element which >= " << DesiredNum << " not found" << endl;
// }

// cout << "\n";

// // upped_bound:
// vector<int> Vec2 = { 4, 5, 3, 1, 6, 7, 10, 9, 8 };
// sort(Vec2.begin(), Vec2.end());
// int DesiredNum2 = 10;
// auto Iterator2 = upper_bound(Vec2.begin(), Vec2.end(), DesiredNum2);
// if(Iterator2 != Vec2.end()) {
//   cout << "First element > " << DesiredNum2 << " is " << *Iterator2 
//        << ", at position " << distance(Vec2.begin(), Iterator2) << endl;
// } else {
//   cout << "Element which > " << DesiredNum2 << " not found" << endl;
// }
// cout << "\n";

//   return 0;
// }

// Обратный порядок:

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {

// vector<int> Vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
// int SizeVec = Vec.size(), i = 1;
// reverse(Vec.begin(), Vec.end());
// for(auto n = Vec.begin(); n != Vec.end(); n++) {
//   cout << *n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// Сумма элементов:

/*
Берёт начальное значение (в данном случае 0).
Последовательно прибавляет к нему каждый элемент вектора.
Возвращает итоговую сумму.
Если 0 (целое число) → суммирование в int.
Если 0.0 (дробное) → суммирование в double.
К третьему аргументу(в нашем случае 0) прибавляются последовательно все элементы массива.
*/

// #include <iostream>
// #include <vector>
// #include <numeric> // std::accumulate

// using namespace std;

// int main() {

// vector<int> Vec = { 4, 5, 3, 1, 6, 7, 10, 9, 8 };
// int Amount = accumulate(Vec.begin(), Vec.end(), 0);
// cout << "Amount is equal " << Amount << endl;

//   return 0;
// }

// Лямбда-выражения с алгоритмами (C++11):

/*
v.begin(), v.end() — итераторы, задающие диапазон (от начала до конца вектора).
[](int x) { ... } — лямбда-функция, которая будет вызвана для каждого элемента.
[] — пустой список захвата (лямбда не использует внешние переменные).
(int x) — параметр: текущий элемент вектора (передаётся по значению).
std::cout << x << " " — действие: вывод элемента и пробела.
*/

/*
В строке for_each(Vec.begin(), Vec.end(), [&i, SizeVec](int x) { символ & перед i означает, 
что переменная i захватывается по ссылке в лямбда-функции.
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {

// vector<int> Vec = { 4, 5, 3, 1, 6, 7, 10, 9, 8 };
// int SizeVec = Vec.size(), i = 1;
// for_each(Vec.begin(), Vec.end(), [&i, SizeVec](int x) {
//   cout << x;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// });
// cout << "\n";

//   return 0;
// }

// Пример с передачей указателя в лямбда-функцию:

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {

// vector<int> Vec = { 4, 5, 3, 1, 6, 7, 10, 9, 8 };
// int SizeVec = Vec.size(), i = 1;
// int* Ptr = &i;
// for_each(Vec.begin(), Vec.end(), [Ptr, SizeVec](int x) {
//   cout << x;
//   if(*Ptr < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   (*Ptr)++;
// });
// cout << "\n";

//   return 0;
// }

// Частичная сортировка:

/*
Элемент на указанной позиции (!!!в отсортированном) (v.begin() + 5) становится таким, 
каким он был бы в полностью отсортированном массиве.
Все элементы до этой позиции будут меньше или равны этому элементу.
Все элементы после этой позиции будут больше или равны ему.
Не гарантирует порядок остальных элементов (они могут быть в любом порядке).
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {

// vector<int> Vec = { 4, 5, 3, 2, 6, 7, 10, 9, 1, 8 }; // sotr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
// int SizeVec = Vec.size(), i = 1;
// nth_element(Vec.begin(), Vec.begin() + 3, Vec.end());
// for(auto n = Vec.begin(); n != Vec.end(); n++) {
//   cout << *n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// Разделение по условию:

/*
Переупорядочивает элементы в диапазоне (Vec.begin(), Vec.end()) так, что:
Сначала идут элементы, удовлетворяющие условию (в вашем случае — чётные).
Затем — все остальные (нечётные).
Возвращает итератор it2, указывающий на первый элемент второй группы (нечётных).

[](int x) { return x % 2 == 0; }:
Возвращает true для чётных чисел (x % 2 == 0).
Возвращает false для нечётных.
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {

// vector<int> Vec = { 4, 5, 3, 2, 6, 7, 10, 9, 1, 8 };
// int SizeVec = Vec.size(), i = 1;

// auto It = partition(Vec.begin(), Vec.end(), [](int x) { return x % 2 == 0; });
// cout << *It << endl;

// for(auto n = Vec.begin(); n != Vec.end(); n++) {
//   cout << *n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// remove_if:

/*
Перемещение элементов, не удовлетворяющих условию в конец:
У элементов перемещенных в конец могут быть перезаписаны значения (т.е отличаться от изначальных)

Vec.erase(NewEnd, Vec.end()):
Чтобы полностью удалить элементы не удовлетворяющие условию (сейчас они перемещены в конец)
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {

// vector<int> Vec = { 4, 5, 3, 2, 6, 7, 10, 9, 1, 8 };
// int SizeVec = Vec.size(), i = 1;

// auto NewEnd = remove_if(Vec.begin(), Vec.end(), [](int x) { return x % 2 == 0; }); // 5 3 7 9 1 | x x x x x, где x - элементы
// cout << *NewEnd << endl;

// for(auto n = Vec.begin(); n != Vec.end(); n++) {
//   cout << *n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

// Vec.erase(NewEnd, Vec.end());

// SizeVec = Vec.size(), i = 1;
// for(const auto& n : Vec) {
//   cout << n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// Итераторы:

// #include <iostream>
// #include <string>
// #include <vector>
// #include <list>

// using namespace std;

// int main() {

// vector<double> Vec = {1.1, 2.2, 3.3, 4.4, 5.5};
// list<std::string>List = {"A", "B", "V", "G", "D"};
// auto FirstElementList = List.begin();
// auto LastElementList = prev(List.end());
// auto LastElementListR = List.rbegin();
// auto FirstElementListR = prev(List.rend());
// int SizeVec = Vec.size();
// int SizeList = List.size();
// int i = 1;

// // Обычные итераторы:
// cout << "Обычные итераторы:\n";

// for(auto n = Vec.begin(); n != Vec.end(); n++) {
//   cout << *n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//     i = 0;
//   }
//   i++;
// }
// cout << "\n";

// for(auto n = prev(List.rend()); n != prev(List.rbegin()); n--) { // Тут вывод через обратные итераторы используя (n--)
//   cout << *n;
//   if(i < SizeList) {
//     cout << ", ";
//   } else {
//     cout << ".";
//     i = 0;
//   }
//   i++;
// }
// cout << "\n";

// cout << *FirstElementList << endl;
// cout << *LastElementList << endl;

// // Обратные итераторы:
// cout << "Обратные итераторы:\n";

// for(auto n = Vec.rbegin(); n != Vec.rend(); n++) {
//   cout << *n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//     i = 0;
//   }
//   i++;
// }
// cout << "\n";

// cout << *FirstElementListR << endl;
// cout << *LastElementListR << endl;

//   return 0;
// }

/*
std::back_inserter - Это итератор вставки в конец вектора, который вызывает 
target.push_back() для каждого элемента.
*/

// #include <iostream>
// #include <string>
// #include <vector>
// #include <list>

// using namespace std;

// int main() {

// vector<double> Vec = {1.1, 2.2, 3.3, 4.4, 5.5};
// list<std::string>List = {"A", "B", "V", "G", "D"};
// // auto FirstElementList = List.begin();
// // auto LastElementList = prev(List.end());
// // auto LastElementListR = List.rbegin();
// // auto FirstElementListR = prev(List.rend());
// int SizeVec = Vec.size();
// int SizeList = List.size();
// int i = 1;

// // Итераторы вставки:
// vector<double> TargetVec;

// copy(Vec.begin(), Vec.end(), back_inserter(TargetVec));
// // /*for (const auto& x : Vec) {
// //     TargetVec.push_back(x);  // Ручное добавление
// // }*/

// for(auto n = TargetVec.begin(); n != TargetVec.end(); n++) {
//   cout << *n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//     i = 0;
//   }
//   i++;
// }
// cout << "\n";

// list<string> TargetList;

// // copy(List.begin(), List.end(), back_inserter(TargetList));
// for(const auto& n : List) {
//   TargetList.push_back(n);
// }

// for(auto n = TargetList.begin(); n != TargetList.end(); n++) {
//   cout << *n;
//   if(i < SizeList) {
//     cout << ", ";
//   } else {
//     cout << ".";
//     i = 0;
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

// Функциональные объекты и лямбды:
/*
Функторы:
Создаётся структура multiply с перегруженным оператором ()
Этот оператор принимает два целых числа и возвращает их произведение
Ключевое слово const означает, что оператор не изменяет состояние объекта
*/

// #include <iostream>
// #include <functional>

// using namespace std;

// struct Multiply {
//   int operator()(int a) const { return a * a; }
// };

// int main() {

// Multiply Ex1;
// // int Result = Ex1(3);
// // cout << Result << endl;
// cout << Ex1(4) << endl;

//   return 0;
// }

// Стандартные функциональные объекты:

/*
std::plus - шаблонный класс из <functional> (Аналогично существуют std::minus, std::multiplies и другие)
*/

// #include <iostream>
// #include <functional> // std::plus

// using namespace std;

// int main() {

// plus<int> add;
// // int sum = add(4, 5);
// // cout << sum << endl;
// cout << add(4, 7) << endl;

//   return 0;
// }

// Лямбда-выражения (C++11):

// #include <iostream>

// using namespace std;

// int main() {

// auto Square = [](int side) { return side * side; };
// cout << Square(6) << endl;

//   return 0;
// }

// Пример комплексного использования библиотеки STL:

/*
std::transform - это алгоритм из стандартной библиотеки C++, 
который применяет заданную операцию к каждому элементу входного диапазона 
и записывает результат в выходной диапазон.
-std::back_inserter(list) - Выходной итератор
-vec.begin() до vec.end() - Входной диапазон
-[](int n) {return std::to_string(n) - Заданная операция

std::to_string - это функция, преобразующая числовое значение в его строковое представление. 
*/

// #include <iostream>
// #include <vector>
// #include <algorithm> // std::binary_search, std::transform
// #include <numeric>
// #include <string>

// using namespace std;

// int main() {

// vector<int> Vec = {1, 5, -1, 6, 3, -7, 34, 2};

// sort(Vec.begin(), Vec.end()); // (-7, -1, 1, 2, 3, 5, 6, 34)

// int DesiredVariable = -1;

// if(binary_search(Vec.begin(), Vec.end(), DesiredVariable)) {
//   cout << "Number " << DesiredVariable << " found in vector" << endl;
// } else {
//   cout << "Number " << DesiredVariable << " not found in vector" << endl;
// }

// vector<string> List;
// transform(Vec.begin(), Vec.end(), back_inserter(List), 
//           [](int n) { return to_string(n); });

// Vec.erase(remove_if(Vec.begin(), Vec.end(),
//                     [](int n) { return n % 2 == 0; }), Vec.end());
// // Альтернативная запись (с явным сохранением итератора):
// // auto NewEnd = remove_if(Vec.begin(), Vec.end(), [](int n) { return n % 2 == 0; });
// // Vec.erase(NewEnd, Vec.end());

// int SizeVec = Vec.size(), i = 1;

// cout << "Odd numbers: " << endl;
// for(const auto& n : Vec) {
//   cout << n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//     i = 0;
//   }
//   i++;
// }
// cout << "\n";

//   return 0;
// }

//-----------------------------------------------------Методы(функции-члены) контейнеров STL:

// erase(...):

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {

// // Удаление элементов входного диапазона:
// std::vector<int> Vec = {1, 2, 3, 4, 5};

// Vec.erase(Vec.begin(), Vec.end() - 2);

// int SizeVec = Vec.size(), i = 1;
// for(const auto& n : Vec) {
//   cout << n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//     i = 0;
//   }
//   i++;
// }
// cout << "\n";

// // Удаление одного элемента:
// Vec = {1, 2, 3, 4, 5};

// Vec.erase(Vec.begin() + 3);

// SizeVec = Vec.size();
// for(const auto& n : Vec) {
//   cout << n;
//   if(i < SizeVec) {
//     cout << ", ";
//   } else {
//     cout << ".";
//     i = 0;
//   }
//   i++;
// }

//   return 0;
// }

// std::distance:

/*
Универсальный способ, работающий для любых итераторов.
Для std::unordered_map, std::unordered_set итераторы не поддерживают std::distance напрямую (только если обходить вручную).
Работает как - (return last - first) для последовательных итераторов, так как итераторы поддерживают арифметику, например vector, array
и            - (size_t count = 0;
                while (first != last) {
                  ++first;
                  ++count;
}
             return count;) для произвольных итераторов(list, set);
*/

// #include <iostream>
// #include <vector>
// #include <list>
// #include <string>

// using namespace std;

// int main() {

// vector<int> Vec = { 11, -1, 23, -5, -6, 123, 1, 3 };
// cout << distance(Vec.begin(), Vec.end()) << endl;

// list<std::string> List = {"D", "a", "n", "y", "a"};
// cout << distance(Vec.begin(), Vec.end()) << endl;

//   return 0;
// }

// empty:

/*
empty() проверяет, пуст ли контейнер (не содержит ли элементов).
*/

/*
Контейнеры, поддерживающие empty():
std::vector
std::string
std::list
std::deque
std::map, std::unordered_map
std::set, std::unordered_set
std::queue, std::stack, std::priority_queue
*/

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {

// vector<int32_t> Numbers;

// if (Numbers.empty()) {
//   cout << "Vector is empty" << endl;
// }

// Numbers.push_back(43);

// if(!Numbers.empty()) {
//   cout << "Vector isn't empty" << endl;
// }

//   return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {

// string Str;

// if(Str.empty()) {
//   cout << "Str is empty" << endl;
// }

// Str = "Danya";

// if(!Str.empty()) {
//   cout << "Str isn't empty" << endl;
// }

//   return 0;
// }

// #include <iostream>
// #include <string>
// #include <map>
// using namespace std;

// int main() {

// map<string, int32_t> MyMap;

// if (MyMap.empty()) {
//   cout << "Map is empty" << endl;
// }
// MyMap = { {"One", 1} };

// if (!MyMap.empty()) {
//   cout << "Map isn't empty" << endl;
// } 


//   return 0;
// }

//-----------------------------------------------------Различные механизмы и функции C++

// try, catch:

/*try и catch — это механизм обработки исключений (exception handling). 
Он позволяет безопасно обрабатывать ошибки, 
которые могут возникнуть во время выполнения программы, вместо аварийного завершения.*/

/*try { ... } — блок, в котором выполняется "опасный" код (например, преобразование строки в число).
Если здесь происходит ошибка, генерируется исключение (exception).

catch (const std::exception& e) { ... } — блок, который перехватывает исключение и обрабатывает его.
В примере ниже он ловит все стандартные исключения (например, std::invalid_argument, std::out_of_range).
*/

/*Может бросить исключение, если argv[1] не число
Если std::stoi не может преобразовать строку в число (например, "abc"), он бросает исключение:
std::invalid_argument — если строка вообще не содержит числа.
std::out_of_range — если число слишком большое для int.
Исключение перехватывается в catch, и программа выводит сообщение об ошибке вместо аварийного завершения.
*/

/*ключевое слово throw используется для явного возбуждения (выброса) исключения. 
Когда выполняется throw, программа прекращает нормальное выполнение и 
начинает искать ближайший подходящий блок catch, который может обработать это исключение.*/

/*std::runtime_error — это класс стандартных исключений в C++, 
предназначенный для обработки ошибок, которые возникают во время 
выполнения программы (отсюда и название runtime — "время выполнения").*/

// #include <iostream>
// #include <limits> // std::numeric_limits
// #include <stdexcept>

// using namespace std;

// int main() {

// try {
//   int Number1 = 0, Number2 = 0;
//   cout << "Enter two integer numbers\n";

//   if(!(cin >> Number1 >> Number2)) {
//     throw runtime_error("Invalid input: not a number");
//   }

//   if((Number2 > 0 && Number1 > numeric_limits<int>::max() - Number2)
// ||
//      (Number2 < 0 && Number1 < numeric_limits<int>::min() - Number2)) {
//       throw overflow_error("Integer overflow");
//      }
  
//   cout << "Result: " << Number1 + Number2 << endl;
// }
// catch (const exception& e) {
//   cerr << "Error: " << e.what() << endl;
//   // return 1; // return только для критичных ошибок, а для пользовательского ввода — продолжайте работу
// }
// catch (...) {
//   cerr << "Unknown error occurred!\n";
//   // return 1; 
// }

//   return 0;
// }

// Простой выброс исключения:

// #include <iostream>
// #include <stdexcept>

// using namespace std;

// int main() {

// try {
//   int Number = 0;
//   cout << "Enter one integer number\n";
//   cin >> Number;

//   if(Number <= 0) {
//     throw runtime_error("number <= 0\n");
//   }
//   cout << "Correct input\n";
// }
//   catch (const exception& e) {
//     cerr << "Caught exception: " << e.what() << endl;
//   }

//   return 0;
// }

// throw с проверкой условия:

// #include <iostream>

// using namespace std;

// void CheckAge(int Age);

// int main() {

// try {

//   int Number = 0;

//   cout << "Enter Age: ";
//   cin >> Number;

//   CheckAge(Number);
// }
// catch (const char* msg) {
//   cerr << "Error: " << msg << endl;
// }

//   return 0;
// }

// void CheckAge(int Age) {
//   if(Age < 0) {
//     throw "Age cannot be negative";
//   }
//   cout << "Age is " << Age << endl;
// }

// Ввод неверных аргументов:

// #include <iostream>
// #include <string> // std::stoi

// using namespace std;

// int main(int argc, char* argv[]) {

// if(argc != 3) {
//   cout << "Correct use: " << argv[0] << " <number1> <number2>" << endl;
//   return 1;
// }

// try {
//   int Number1 = stoi(argv[1]);
//   int Number2 = stoi(argv[2]);

//   cout << "Amount argv[1], argv[2] = " << Number1 + Number2 << endl;
// }
// catch (const exception& e) {
//   cerr << "Error: enter two integer numbers\n";
//   return 1;
// }

//   return 0;
// }

// Ловим конкретные исключения:

// #include <iostream>

// using namespace std;

// int main(int argc, char* argv[]) {

// if(argc != 2) {
//   cout << "Correct use: " << argv[0] << "<number>" << endl;
//   return 1;
// }

// try {
//   int Number = stoi(argv[1]);

//   cout << "Entered number: " << Number << endl;
// }
// catch (const invalid_argument& e) {
//   cerr << "Error: It's not a number\n";
// }
// catch(const out_of_range& e) {
//   cerr << "Integer overflow\n";
// }

//   return 0;
// }






// enum, enum class:

// enum:

/*enum (перечисление) — это пользовательский тип данных, 
который позволяет создать набор именованных целочисленных констант. */

// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// enum LogLevel {
//   SUCCESS = 10,
//   ERROR = 20
// };

// int CheckCode(LogLevel Level);

// int main() {

// int ResultFunc = CheckCode(LogLevel::SUCCESS);
// if(ResultFunc == 10) {
//   cout << "SUCCESS(" << ResultFunc << ")" << endl;
// } else {
//   cout << "ERROR(" << ResultFunc << ")" << endl;
// }

//   return 0;
// }

// int CheckCode(LogLevel Level) {
//   LogLevel StatusFunc;
//   ofstream LogFile("App.log", ios::app);
//   string LevelStr;
//   int StatusCode = 0;

//   switch (Level) {
//     case SUCCESS:
//       LevelStr = "[SUCCESS]";
//       StatusCode = 10;
//       break;
//     case ERROR:
//       LevelStr = "[ERROR]";
//       StatusCode = 20;
//       break;
//   }

//   if(StatusCode == 10) {
//     LogFile << LevelStr << endl;
//     StatusFunc = LogLevel::SUCCESS;
//   } else {
//     LogFile << LevelStr << endl;
//     StatusFunc = LogLevel::ERROR;
//   }

//   return StatusFunc;
// }

// enum class (более безопасный вариант):

/*Требует явного указания области видимости, т.е:
- log(LogLevel::INFO, "Сообщение"); - Правильно 
- log(INFO, "Сообщение"); - Ошибка

  std::ofstream LogFile("App.log", std::ios::app); // Первый аргумент не различает регистры
*/

// #include <iostream>
// #include <string>
// #include <fstream>

// using namespace std;

// enum class LogLevel { FATAL, ERROR, WARN, INFO }; 

// void log(LogLevel Level);
 
// int main() {

// log(LogLevel::FATAL);

//   return 0;
// }

// void log(LogLevel Level) {

//   ofstream LogFile("App.log", ios::app);
//   string LevelStr;
//   int StatusCode = 0;
//   string Message;

//   switch (Level) {
//     case LogLevel::FATAL:
//       LevelStr = "[FATAL]";
//       StatusCode = 20;
//         break;
//     case LogLevel::ERROR:
//       LevelStr = "[ERROR]";
//       StatusCode = 30;
//         break;
//     case LogLevel::WARN:
//       LevelStr = "[WARN]";
//       StatusCode = 40;
//         break;
//     case LogLevel::INFO:
//       LevelStr = "[INFO]";
//       StatusCode = 50;
//         break;
//   }

//   if (StatusCode == 20) {
//     Message = "FATAL CODE\n";
//   } else if (StatusCode == 30) {
//     Message = "ERROR CODE\n";
//   } else if (StatusCode == 40) {
//     Message = "WARN CODE\n";
//   } else if (StatusCode == 50) {
//     Message = "INFO CODE\n";
//   }

//   LogFile << LevelStr << endl;
//   cout << Message << endl;
// }

// Пример логирования:

// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// enum LogLevel { FATAL, ERROR, WARN, INFO, DEBUG, TRACE}; // Определение уровней логирования. Создаётся перечисление (enum) с уровнями логирования:

// void Log(LogLevel Level);

// int main() {

// Log(LogLevel::FATAL);
// Log(LogLevel::ERROR);
// Log(LogLevel::WARN);
// Log(LogLevel::INFO);
// Log(LogLevel::DEBUG);
// Log(LogLevel::TRACE);
  
//   return 0;
// }

// void Log(LogLevel Level) {
//   ofstream LogFile("app.log", ios::app); // std::ios::app означает, что новые записи будут добавляться в конец файла
//   string LevelStr;
//   string Message;


//   switch (Level) {
//     case FATAL:
//       LevelStr = "[FATAL]";
//       Message = "FATAL CODE";
//         break;
//     case ERROR:
//       LevelStr = "[ERROR]";
//       Message = "ERROR CODE";
//         break;
//     case WARN:
//       LevelStr = "[WARN]";
//       Message = "WARN CODE";
//         break;
//     case INFO:
//       LevelStr = "[INFO]";
//       Message = "INFO CODE";
//         break;
//     case DEBUG:
//       LevelStr = "[DEBUG]";
//       Message = "DEBUG CODE";
//         break;
//     case TRACE:
//       LevelStr = "[TRACE]";
//       Message = "TRACE CODE";
//         break;
//   }

//   if(LevelStr == "[FATAL]") {
//     LogFile << LevelStr << ": " << Message << endl;
//   } else if (LevelStr == "[ERROR]") {
//     LogFile << LevelStr << ": " << Message << endl;
//   } else if (LevelStr == "[WARN]") {
//     LogFile << LevelStr << ": " << Message << endl;
//   } else if (LevelStr == "[INFO]") {
//     LogFile << LevelStr << ": " << Message << endl;
//   } else if (LevelStr == "[DEBUG]") {
//     LogFile << LevelStr << ": " << Message << endl;
//   } else if (LevelStr == "[TRACE]") {
//     LogFile << LevelStr << ": " << Message << endl;
//   }
// }

// Шаблоны функций (Function Templates) template:

/*
В C++ шаблоны (templates) — это мощный механизм для создания универсальных функций и классов, 
которые могут работать с различными типами данных без их явного указания на этапе написания кода.

template - ключевое слово, что это ШАБЛОН
<typename T> - параметр шаблона, где T - любой тип данных
T - тип, который будет определен при вызове функции
getMax - имя функции
(T a, T b) - два параметра одного типа T

typename (или class) - указывает, что T является параметром типа:
template <typename T>  // T - любой тип: int, double, string, etc.
template <class T>     // абсолютно то же самое!
*/

/*
В контексте шаблонов class и typename полностью взаимозаменяемы. 
Исторически использовали class, но typename более четко указывает, 
что можно использовать любые типы, а не только классы
*/

// #include <iostream>
// using namespace std;

// // Шаблон функции для нахождения максимума:
// template <typename T>
// T getMax(T a, T b) {
//   return (a > b) ? a : b;
// }

// int main() {

// cout << getMax(5, 10) << endl;
// cout << getMax(3.14, 2.71) << endl;
// cout << getMax('a', 'z') << endl;

//   return 0;
// }

// #include <iostream>
// using namespace std;

// template <typename T1, typename T2>
// void PrintPair(T1 First, T2 Second) {
//   cout << First << " : " << Second << endl;
// }

// int main() {

// PrintPair("Age", 23);
// PrintPair(23, "Age");

//   return 0;
// }

// #include <iostream>
// using namespace std;

// template <typename Type>
// class Box {
//   private:
//     Type Content;
//   public:
//     Box(Type C) : Content(C) {}

//     void SetContent(Type NewContent) {
//       Content = NewContent;
//     }

//     Type GetContent() {
//       return Content;
//     }
// };

// int main() {

// // Box<string> Box1("Danya");
// Box Box1("Borya");

// cout << Box1.GetContent() << endl;
// Box1.SetContent("Masha");
// cout << Box1.GetContent() << endl;

// Box Box2(2);

// cout << Box2.GetContent() << endl;

//   return 0;
// }

// #include <iostream>
// using namespace std;

// template <typename Type1, typename Type2>
// class Pair {
//   private:
//     Type1 First;
//     Type2 Second;
//   public: 
//     Pair(Type1 F, Type2 S) : First(F), Second(S) {}

//     Type1 GetFirst() { return First; }
//     Type2 GetSecond() { return Second; }

//     void DisplayInfo() {cout << "(" << GetFirst() << ", " << GetSecond() << ")" << endl;}
// };

// int main() {

// Pair<string, int> Person1("Danya", 25);

// Person1.DisplayInfo();

// Pair<string, int> Product("Apple", 2.5);

// Product.DisplayInfo();

//   return 0;
// }

// Особенная версия шаблонной функции только для конкретного типа (string).
/*
Специализации не работают без общего шаблона (template <typename Type>), 
потому что они являются частными случаями общего шаблона, а не самостоятельными функциями.

Как работает:

Когда компилятор видит вызов PrintType(value):
Ищет функцию PrintType
Находит общий шаблон template<typename Type> void PrintType(Type)
Проверяет: есть ли специализация для конкретного типа?
Если есть - использует специализацию
*/

// #include <iostream>
// #include <string>
// #include <cstdint>
// using namespace std;

// template <typename Type>
// void PrintType(Type A) { 
//   cout << "Meaning: " << A << endl;
// }

// template <>
// void PrintType<string>(string Value) {
//   cout << "Meaning string: " << Value << endl;
// }

// template <>
// void PrintType<double>(double B) {
//   cout << "Meaning double: " << B << endl;
// }

// template <>
// void PrintType<int*>(int* C) {
//   cout << "Pointer: " << C << ", meaning pointer: " << *C << endl;
// }

// int main() {

// PrintType(234);
// PrintType("Borya");
// PrintType(string("Danya"));
// PrintType(double(3.14));

// int32_t Variable = 342;
// int32_t* ptr = &Variable;
// PrintType(ptr);

//   return 0;
// }

// Пример программы с template:



// union:

/*
В C++ union (объединение) — это специальный тип данных, 
который позволяет хранить разные типы данных в одной области памяти. 

Ключевые особенности:
Общая память: Все члены union занимают одну и ту же область памяти
Размер: Размер union равен размеру самого большого члена
Одновременное использование: В любой момент времени может использоваться только один член.

Важные предупреждения:
Небезопасно: Нет встроенной проверки того, какой член активен
В современном C++ предпочтительнее использовать std::variant или полиморфизм
С классами в union требуется ручное управление памятью
Union — мощный инструмент, но требует осторожного использования из-за отсутствия type safety.
*/

// #include <iostream>
// using namespace std;

// union Data {
//   int VariableInt;
//   float VariableFloat;
// };

// int main() {

// Data VariableUnion;

// VariableUnion.VariableInt = 10; // VariableUnion.VariableInt теперь содержит мусор
// cout << "Integer: " << VariableUnion.VariableInt << endl;

// VariableUnion.VariableFloat = 3.14;
// cout << "Float: " << VariableUnion.VariableFloat << endl;

//   return 0;
// }

// #include <iostream>
// #include <cstring> // для strcpy
// #include <vector>
// using namespace std;

// struct Widget {
//   enum Type {INT, FLOAT, STRING} type;
//   union {
//     int VariableInt;
//     float VariableFloat;
//     char* VariableChar;
//   };

//   Widget(int Value) : type(INT), VariableInt(Value) {}
//   Widget(float Value) : type(FLOAT), VariableFloat(Value) {}
//   Widget(const char* Value) : type(STRING) {
//     VariableChar = new char[strlen(Value) + 1];
//     strcpy(VariableChar, Value);
//   }

//   virtual ~Widget() {
//     if (type == STRING) {
//       delete[] VariableChar;
//     }
//   }

//   // Копирующий конструктор:
//   Widget(const Widget& Other) : type(Other.type) {
//     switch (type) {
//       case INT:
//         VariableInt = Other.VariableInt;
//           break;
//       case FLOAT:
//         VariableFloat = Other.VariableFloat;
//           break;
//       case STRING:
//         VariableChar = new char[strlen(Other.VariableChar) + 1];
//         strcpy(VariableChar, Other.VariableChar);
//           break;
//     }
//   }

//   // Метод для вывода значения:
//   void Print() const {
//     switch (type) {
//       case INT:
//         cout << "Integer: " << VariableInt << endl;
//           break;
//       case FLOAT:
//         cout << "Float: " << VariableFloat << endl;
//           break;
//       case STRING:
//         cout << "String: " << VariableChar << endl;
//           break;
//     }
//   }
// };

// int main() {

//  // Создание виджетов разных типов:
//  Widget W1(42);
//  Widget W2(3.14f);
//  Widget W3("I love Cpp");
//  Widget W4(Widget(110)); // Вызывается копирующий конструктор

//  W1.Print();
//  W2.Print();
//  W3.Print();
//  W4.Print();

//  // Массив виджетов:
//  Widget Widgets[] = {
//   Widget(100), // Вызывается копирующий конструктор
//   Widget(2.71f), // Вызывается копирующий конструктор
//   Widget("Hello Cpp") // Вызывается копирующий конструктор
//  };
//  cout << "\n";

//  cout << "Array of widgets:" << endl;
//  for (const auto& N : Widgets) {
//   N.Print();
//  }
//   cout << "\n";

//  vector<Widget> Vec;
//  Widget Q(42);
//  Vec.push_back(Q); // Вызывается копирующий конструктор

//  // Изменение значения с проверкой типа:
//  Widget W(123);
//  W.Print();
//   cout << "\n";

//  // Меняем тип на float:
//  W.type = Widget::FLOAT;
//  W.VariableFloat = 99.9f;
//  W.Print();

//   return 0;
// }







//-----------------------------------------------------Многопоточность

/*
Многопоточность в C++ позволяет выполнять несколько потоков выполнения одновременно, 
что может значительно повысить производительность программ, особенно на многоядерных процессорах.
*/

// Основные способы работы с потоками в C++:

// Стандартная библиотека <thread> (C++11 и выше):

/*

*/

// #include <iostream>
// #include <thread> // библиотека для работы с потоками (std::thread)
// #include <chrono> // библиотека для работы со временем (std::chrono)

// using namespace std;
// using namespace chrono;

// void ThreadFunction(int n); // Объявляем функцию, которая будет выполняться в отдельном потоке

// int main() {

// thread t(ThreadFunction, 5); // Создаем новый поток, который будет выполнять thread_function с аргументом 5

// // Основной поток продолжает выполнять этот код:
// for (int i = 0; i < 3; ++i) {
//   cout << "Main flow: " << i << endl;
//   this_thread::sleep_for(milliseconds(300)); // Пауза 300 мс
// }

// t.join(); // // Ожидание завершения потока t

//   return 0;
// }

// void ThreadFunction(int n) {
//   for (int i = 0; i < n; ++i) {
//     cout << "Flow is working: " << i << endl;
//     this_thread::sleep_for(milliseconds(500)); // // Приостановка потока на 500 мс
//   }
// }

// Асинхронное выполнение с <future>:

// #include <iostream>
// #include <future>
// #include <cmath>
// // #include <chrono>
// // #include <thread>

// using namespace std;
// using namespace chrono;

// double CalculatePi (int Terms);

// int main() {

//   // for (int i = 0; i < 3; ++i) 
//   // cout << "Main flow: " << i << endl;
//   // this_thread::sleep_for(milliseconds(300)); // Пауза 300 мс

//   future<double> Pi = async(CalculatePi, 1'000'000'000);

//   cout << "Вычисление π в фоновом режиме..." << endl;

//   cout << "π ≈ " << Pi.get() << endl;


//   return 0;
// }

// double CalculatePi (int Terms) {
//   double sum = 0.0;
//   for (int i = 0; i < Terms; ++i) {
//     int Sign = pow(-1, i);
//     double Term = 1.0 / (i * 2 + 1);
//     sum += Sign * Term;
//   }

//   return sum * 4;
// }

//-----------------------------------------------------Бинарный код

/*
int8_t Variable1 = 0b11111111;
cout << Variable1 << endl; - 
int8_t (и uint8_t) - это просто псевдонимы для signed char и unsigned char соответственно. 
Когда вы пытаетесь вывести int8_t через cout, он обрабатывается как символ, а не как число.

uint8_t Variable2 = 0b11111111;
cout << Variable2 << endl; - 
Символ с кодом 255 в ASCII - это непечатаемый управляющий символ 
(ÿ в некоторых кодировках, но часто невидимый)
Поэтому консоль пытается отобразить символ, но он невидим

Арифметический сдвиг вправо для отрицательных чисел (>> 1):
Сдвигает биты вправо
Заполняет старшие биты единицами (сохраняет знак)
Сохраняет знак числа
*/

// #include <iostream>
// #include <cstdint> // Для int8_t, uint8_t

// using namespace std;

// int main() {

// signed int Variable = static_cast<int8_t>(0b11111111);
// cout << "1) " << Variable << endl;;

// int8_t Variable1 = 0b01111110;
// cout << "2) " << Variable1 << endl;

// uint8_t Variable2 = 0b11111111;
// cout << "3) " << Variable2 << endl;

// int8_t Variable3 = 0b01111110;
// cout << "4) " << static_cast<int>(Variable3) << endl;

// uint8_t Variable4 = 0b11111111;
// cout << "5) " << static_cast<int>(Variable4) << endl;

// int16_t Variable5 = 0b1111111111111111;
// cout << "6) " << Variable5 << endl;

// uint16_t Variable6 = 0b1111111111111111;
// cout << "7) " << Variable6 << endl;

// int32_t Variable7 = 0b11111111 >> 2;
// // Variable7 = Variable7 >> 2;
// cout << "8) " << Variable7 << endl;

// int Variable8 = 0b11111111111111111111111111111111 >> 1;
// cout << "9) " << Variable8 << endl;

// int Variable9 = -1 >> 1;
// cout << "10) " << Variable9 << endl;

// int Variable10 = 1 >> 1;
// cout << "11) " << Variable10 << endl;

// int Variable11 = 0b10000000000000000000000000000001;
// cout << "12) " << Variable11 << endl;

// int Variable12 = 0b11111111111111111111111100000001;
// cout << "13) " << Variable12 << endl;

// int Variable13 = 0b11111111111111111111111110000000;
// cout << "14) " << Variable13 << endl;

// int Variable14 = 0b11111111;
// cout << "15) " << Variable14 << endl;

// int Variable15 = 0b11111111 >> 1;
// cout << "16) " << Variable15 << endl;

// int Variable16 = -0b11111111;
// cout << "17) " << Variable16 << endl;

// int Variable17 = -0b11111111 >> 1;
// cout << "18) " << Variable17 << endl;

// int Variable18 = -(0b11111111 >> 1);
// cout << "19) " << Variable18 << endl;

// int Variable19 = 0b11111111111111111111111100000001;
// cout << "20) " << Variable19 << endl;

// int Variable20 = 0b11111111111111111111111100000000;
// cout << "21) " << Variable20 << endl;

// int Variable21 = -0b11111111111111111111111100000000;
// cout << "22) " << Variable21 << endl;

// int Variable22 = -1 >> 31; // 32 будет warning
// cout << "23) " << Variable22 << endl;

// int16_t Variable23 = 0b1111111110000000;
// cout << "24) " << Variable23 << endl;

// int16_t Variable24 = 0b0111111110000000;
// cout << "25) " << Variable24 << endl;

// int32_t Variable25 = 0b0111111110000000;
// cout << "26) " << Variable25 << endl;

//   return 0;
// // }

// // Ручная реализация с битовыми операциями

// #include <iostream>

// using namespace std;

// void PrintBinary(int Number, int Bits = 32);

// int main() {

// int Variable = 132;
// PrintBinary(Variable);
// PrintBinary(Variable, 8);

//   return 0;
// }

// void PrintBinary(int Number, int Bits) {
//   for (int i = Bits - 1; i >= 0 ; i--) {
//     cout << ((Number >> i) & 1);
//     if (i % 4 == 0 && i != 0) {
//       cout << " ";
//     } else if (i == 0) cout << " \n";
//   } 
// }

// Использование std::bitset:

// #include <iostream>
// #include <bitset>
// #include <cstdint>

// using namespace std;

// int main() {

// int32_t Number = 32;

// // Вывод 8-битного представления:
// cout << "8-bit:  " << bitset<8>(Number) << endl;

// // Вывод 16-битного представления:
// cout << "16-bit: " << bitset<16>(Number) << endl;

// // Вывод 32-битного представления:
// cout << "32-bit: " << bitset<32>(Number) << endl;

//   return 0;
// }

// std::bitset для разных типов:

// #include <iostream>
// #include <bitset>
// #include <cstdint>

// using namespace std;

// int main() {

// char Symbol = 'B';
// cout << "Char B: " << bitset<8>(Symbol) << endl;

// unsigned int Variable = 4294967295;
// cout << "Unsigned int 1234: " << bitset<32>(Variable) << endl;

// int Variable2 = -2147483648;
// cout << "Unsigned int 1234: " << bitset<32>(Variable2) << endl;

// // Для float необходимо reinterpret_cast'

// float Variable3 = 3.14;
// unsigned int FloatBits = *reinterpret_cast<unsigned int*>(&Variable3);
// cout << "float 3.14: " << bitset<32>(FloatBits) << endl;

//   return 0;
// }

// Первый способ перевода float в битовое представление:

/*
Эта строка выполняет реинтерпретацию битового представления числа с 
плавающей точкой как целого беззнакового числа. Давайте разберем по шагам:

&Variable3:
Получаем адрес переменной Variable3 (тип float*)

reinterpret_cast<unsigned int*>(&Variable3):
Преобразуем указатель float* в указатель unsigned int*

*reinterpret_cast<unsigned int*>(&Variable3):
Разыменовываем указатель - получаем значение типа unsigned int,
но которое на самом деле представляет биты float

Что происходит на практике:
float Variable3 = -34.231f; // Число в формате IEEE 754

Битовая реинтерпретация:
БИТЫ float │ БИТЫ unsigned int
11000010 00001000 01110111 00001101 = -34.231f
11000010 00001000 01110111 00001101 = 3254986509 (как unsigned int)
*/

// #include <iostream>
// #include <bitset>
// #include <cstdint>
// using namespace std;

// int main() {

// int32_t Variable = -1;
// cout << bitset<32>(Variable) << endl;

// char Symbol = 'C';
// cout << bitset<8>(Symbol) << endl;

// uint32_t Variable2 = 12341;
// cout << bitset<32>(Variable2) << endl;

// float Variable3 = -34.231;
// unsigned int FloatBits = *reinterpret_cast<unsigned int*>(&Variable3);
// cout << bitset<32>(FloatBits) << endl;

//   return 0;
// }

// Второй способ перевода float в битовое представление:

// #include <iostream>
// #include <cstdint>
// #include <bitset>
// using namespace std;

// int main() {

//   float Variable = 3.1234;

//   union FloatIntUnion {
//     float F;
//     uint32_t I;
//   };

//   FloatIntUnion U;
//   U.F = Variable;
//   cout << bitset<32>(U.I) << endl;

//   return 0;
// }

// Третий способ перевода float в битовое представление:

/*
Аргумент sizeof(float) в функции memcpy очень важен - он определяет количество байтов, которые будут скопированы.
Копируется ровно 4 байта из Variable3 (float) в FloatBits (uint32_t).
*/

// #include <iostream>
// #include <bitset>
// #include <cstdint>
// #include <cstring>
// using namespace std;

// int main() {

//   float Variable = 34.123;

//   uint32_t FloatBits;
//   memcpy(&FloatBits, &Variable, sizeof(float));
//   cout << bitset<32>(FloatBits) << endl;

//   return 0;
// }

//-----------------------------------------------------Алгоритмы:

// Сумма чисел от 1 до N:
// #include <iostream>

// int main () {

// int arr[11] = {12, 45, 56, 34, 76, 12, 54, 87, 98, 11, 34};
// size_t size = sizeof(arr) / sizeof(int);
// int sum = 0;

// for(size_t i = 0; i < size; i++) {
//   sum += arr[i];
// }
// std::cout << sum << std::endl;

//   return 0;
// }

// Вычислить факториал числа N(N!):

// #include <iostream>

// int main() {

// int Number = 6;
// int Result = 1;

// for (int i = 1; i < Number + 1; i++) {
//   Result *= i;
// }
// std::cout << Result << std::endl;

//   return 0;
// }

// Числа Фибоначчи:

// #include <iostream>

// using namespace std;

// int main () {

// int n = 40;
// int arr[n] = {0, 1, 1};
// size_t size = sizeof(arr) / sizeof(int);

// for(size_t i = 1; i < size; i++) {
//   arr[i + 2] = arr[i] + arr[i + 1];
// }

// cout << arr[3] << endl;

// for (size_t i = 0; i < size; i++) {
//   cout << arr[i] << (i < size - 1 ? ", " : ".\n");
// }

//   return 0;
// }

// Определить является ли число простым (делится только на 1 и на само себя):

// #include <iostream>
// #include <cmath>

// int isPrime (int a) {
//   int error = 1;
//   if (a <= 1) {
//     error = 0;
//   } 
//   if (a == 2) {
//     error = 1;
//   }
//   if (a % 2 == 0) {
//     error = 0;
//   }
//   for (int i = 3; i <= sqrt(a); i += 2) {
//     if (a % i == 0) {
//       error = 0;
//     }
//   }

//   return error;
// }

// int main () {

// int number;
// std::cout << "Введите число для проверки" << "\n";
// std::cin >> number;

// if(isPrime(number)) {
//   std::cout << number << " - простое число" << std::endl;
// } else {
//   std::cout << number << " - не является простым числом" << std::endl;
// }

//   return 0;
// }

// Разворачивание строки ("hello" → "olleh"):

// #include <iostream>
// #include <cstring>

// int main () {
// char string[100];
// std::cout << "Введите строку: " << "\n";
// std::cin >> string;
// char stringRes[100];
// size_t size = strlen(string);
// int j = 1;

// for(int i = 0; i < size; i++) {
//   stringRes[i] = string[i];
// }
// for(int i = 0; i < size; i++) {
//   string[i] = stringRes[i + (size - j)];
//   j += 2;
// }

// for(int i = 0; i < size; i++) {
//   std::cout << string[i];
// }
// std::cout << std::endl;

//   return 0;
// }

// Проверка на полиндром (топот" → полиндром, "привет" → не полиндром):
/*(A man, a plan, a canal – Panama) - фраза полиндром*/

// #include <iostream>
// #include <cstring>

// int main () {

// char string[100] = "racecar";
// size_t size = strlen(string);

// if (string[0] == string[0 + size - 1]) {
//   std::cout << "Слово " << string << " - Полиндром" << std::endl;
// } else {
//   std::cout << "Слово " << string << " - не является полиндромом" << std::endl;
// }

//   return 0;
// }

// Удаление заданного элемента массива по индексу элемента:

// #include <iostream>
// #include <vector>

// int main() {

// std::vector<long> vec = {1124231, 234352, 23433};

// size_t index = 3;
// if(index < vec.size()) {
//   vec.erase(vec.begin() + index);
// } else {
//   std::cout << "Индекс выходит за границы вектора!" << std::endl;
// }

// for (auto n = vec.begin(); n != vec.end(); n++) {
//   std::cout << *n << " ";
// }
// std::cout << "\n";

// for (auto n = vec.rbegin(); n != vec.rend(); n++) {
//   std::cout << *n << " ";
// }

//   return 0;
// }

// Удаление заданного элемента массива по индексу элемента (в последовательном контейнере list):

// #include <iostream>
// #include <list>

// int main() {

// std::list<std::string> list = {"Danya", "Diana"};

// size_t index = 1;
// if(index < list.size()) {
//   auto it = list.begin();
//   std::advance(it, index);
//   list.erase(it);
// }

// for(auto n = list.begin(); n != list.end(); n++) {
//   std::cout << *n << " ";
// }
// std::cout << "\n";

//   return 0;
// }

// BubbleSort: 

// #include <iostream>

// void PrintArray(int32_t Arr[], int32_t SizeArr);
// void BubbleSort(int32_t Arr[], int32_t SizeArr);

// int main() {

// int32_t Array[] = {10, 5, 2, 3, 1, 6, 8, 7, 9, 4};
// int32_t SizeArray = sizeof(Array) / sizeof(int32_t);

// PrintArray(Array, SizeArray);
// BubbleSort(Array, SizeArray);
// PrintArray(Array, SizeArray);

//   return 0;
// }

// void PrintArray(int32_t Arr[], int32_t SizeArr) {
//   for (int i = 0; i < SizeArr; i++) {
//     std::cout << Arr[i] << (i < SizeArr - 1 ? ", " : ".\n");
//   }
// }

// void BubbleSort(int32_t Arr[], int32_t SizeArr) {
//   for (int i = 0; i < SizeArr - 1; i++) {
//     for (int j = 0; j < SizeArr - i - 1; j++) {
//       if (Arr[j] > Arr[j + 1]) {
//         int32_t Template = Arr[j];
//         Arr[j] = Arr[j + 1];
//         Arr[j + 1] = Template;
//       }
//     }
//   }
// }

// Обход двоичного дерева:

// #include <iostream>
// #include <queue> // для обхода в ширину (BFS)

// struct TreeNode {
//   int val;
//   TreeNode* left;
//   TreeNode* right;
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// void preOrder(TreeNode* root);
// void inOrder(TreeNode* root);
// void postOrder(TreeNode* root);
// void levelOrder(TreeNode* root);
// void freeClean (TreeNode* root);

// int main () {

// TreeNode* root = new TreeNode(1);
// root->left = new TreeNode(2);
// root->right = new TreeNode(3);
// root->left->left = new TreeNode(4);
// root->left->right = new TreeNode(5);

// std::cout << "PreOrder: ";
// preOrder(root);
// std::cout << "\ninOrder: ";
// inOrder(root);
// std::cout << "\npostOrder: ";
// postOrder(root);
// std::cout << "\nlevelOrder: ";
// levelOrder(root);

// freeClean(root);

//   return 0;
// }

// // Префиксный обход (Pre-order)
// void preOrder(TreeNode* root) {
//   if (root == nullptr) return;
//   std::cout << root->val << " ";
//   preOrder(root->left);
//   preOrder(root->right);
// }
// // Инфиксный обход (In-order)
// void inOrder(TreeNode* root) {
//   if (root == nullptr) {return;}
//   inOrder(root->left);
//   std::cout << root->val << " ";
//   inOrder(root->right);
// }
// // Постфиксный обход (Post-order)
// void postOrder(TreeNode* root) {
//   if (root == nullptr) {return;}
//   postOrder(root->left);
//   postOrder(root->right);
//   std::cout << root->val << " ";
// }
// // Обход в ширину (Level-order, BFS)
// void levelOrder(TreeNode* root) {
//   if (root == nullptr) {return;}
//   std::queue<TreeNode*> q;
//   q.push(root);

//   while (!q.empty()) {
//     TreeNode* current = q.front();
//     q.pop();
//     std::cout << current->val << " ";

//     if (current->left != nullptr) q.push(current->left);
//     if (current->right != nullptr) q.push(current->right);
//   }
// }
// void freeClean (TreeNode* root) {
//   if (root == nullptr) {return;}
//   freeClean(root->left);
//   freeClean(root->right);
//   delete(root);
// }

//-----------------------------------------------------Разные программы:

// #include <iostream>
// #include <string>

// class cars {
//   public:
//     virtual void output() = 0;
//     virtual void output1() = 0;
//     virtual void output2() = 0;
// };

// class lada: public cars {
//   private:
//     std::string model;
//     double speed;
//     double weight;
//     double cost;
//   public:   

//     lada() {}
//     lada(std::string m) : model(m) {}
//     lada(double s, double w) : speed(s), weight(w) {}
//     lada(double c) : cost(c) {}

//     void output() override {
//       std::cout << "Модель: " << model << std::endl;
//     }
//     void output1() override {
//       std::cout << "Характеристики: " << speed << "km/h" << ", " << weight << "kg" << std:: endl;
//     }
//     void output2() override {
//       std::cout << "Цена: " << cost << "₽" << std::endl;
//     }
// };

// class bmw: public cars {
//   private:
//     std::string model;
//     double speed;
//     double weight;
//     double cost;
//   public:

//     bmw() {}
//     bmw(std::string m) : model(m) {}
//     bmw(double s, double w) : speed(s), weight(w) {}

//     void output() override {
//       std::cout << "Модель: " << model << std::endl;
//     }
//     void output1() override {
//       std::cout << "Характеристики: " << speed << "km/h" << ", " << weight << "kg" << std:: endl;
//     }
//     void output2() override {
//       std::cout << "Цена: " << cost << "₽" << std::endl;    }

// };

// int main () {

// cars *car[3];
// car[0] = new lada();
// car[1] = new lada("vesta");
// car[2] = new lada(250, 3000);
// car[3] = new lada(1500000);

// car[0]->output();
// car[1]->output();
// car[2]->output1();
// car[3]->output2();

// for (int i = 0; i < 4; i++) {
//   delete car[i];
//   car[i] = nullptr;
// }

//   return 0;
// }

/*
Функция предоставляет доступ к полю Model структуры Car
Возвращается ссылка на int, т.е. доступ предоставляется как на чтерние, так и на запись
*/

// #include <iostream>
// #include <string>
// using namespace std;

// struct Car {
//   private:
//     string Model = "Vesta";
//     double Weight = 2500.50;
//     int32_t Speed = 450;
// };

// struct Car2 {
//   public:
//     string Model2;
//     double Weight2;
//     int32_t Speed2;
// };

// string &GetModel(Car& Car3) {
//   void* Voidptr = static_cast<void*>(&Car3);
//   struct Car2* P = static_cast<Car2*>(Voidptr);
//   return P->Model2;
// }

// double &GetWeight(Car& Car3) {
//   void* Voidptr = static_cast<void*>(&Car3);
//   struct Car2* P = static_cast<Car2*>(Voidptr);
//   return P->Weight2;
// }

// int32_t &GetSpeed(Car& Car3) {
//   void* Voidptr = static_cast<void*>(&Car3);
//   struct Car2* P = static_cast<Car2*>(Voidptr);
//   return P->Speed2;
// }

// int main() {

//   Car Obj;
//   cout << GetModel(Obj) << endl;
//   cout << GetWeight(Obj) << endl;
//   cout << GetSpeed(Obj) << endl;

//   return 0;
// }
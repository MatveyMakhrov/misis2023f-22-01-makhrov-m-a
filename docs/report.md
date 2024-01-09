

# Вопрос по выбору 
## “Паттерн Strategy”
### Выполнил 
Студент группы БПМ-22-1 
Махров Матвей Александрович

## _Что такое паттер Strategy?_
Паттерн Strategy — это шаблон поведенческого проектирования, который определяет семейство взаимозаменяемых алгоритмов и позволяет использовать их взаимозаменяемо в контексте.
Этот паттерн позволяет выбирать алгоритм во время выполнения, обеспечивая гибкость и способствуя повторному использованию кода. 

## _Пример паттерна Strategy._

Задача: например, человек работает над приложением для обработки данных, и вам нужно реализовать функцию сортировки, которая позволяет пользователям сортировать данные различными способами.
Этот человек решил использовать паттерн Strategy для работы с различными алгоритмами сортировки. 
## _Реализация паттерна Strategy._ 
### Ключевые компоненты паттерна strategy: 
- Context: класс, который содержит ссылку на интерфейс стратегии и отвечает за выполнение алгоритма.
- Интерфейс стратегии: интерфейс или абстрактный класс, который объявляет методы для алгоритма. Этот класс реализуется различными стратегиями. 
- Конкретные стратегии: различные алгоритмы, реализующие интерфейс стратегии

##### Шаг 1: Определить интерфейс стратегии

```c++
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& arr) = 0;
};
```   

##### Шаг 2: Реализовать конкретные стратегии

```c++
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override {
        // Implement Bubble Sort algorithm
    }
};
 
class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override {
        // Implement Quick Sort algorithm
    }
};

//Add more sorting algorithms as needed
``` 

##### Шаг 3: Создать контекст

```c++
class SortContext {
private:
    SortingStrategy* strategy;
 
public:
    void setStrategy(SortingStrategy* strategy) {
        this->strategy = strategy;
    }
 
    void executeStrategy(std::vector<int>& arr) {
        strategy->sort(arr);
    }
};
``` 

##### Шаг 4: Использовать паттерн strategy

```c++
int main() {
    std::vector<int> data = {5, 2, 7, 1, 9};
 
    SortContext context;
    BubbleSort bubbleSort;
    QuickSort quickSort;
 
    context.setStrategy(&bubbleSort);
    context.executeStrategy(data); // Executes Bubble Sort
 
    context.setStrategy(&quickSort);
    context.executeStrategy(data); // Executes Quick Sort
 
    return 0;
}

``` 

### Схематическое представление паттерна Strategy

![image](https://github.com/MatveyMakhrov/misis2023f-22-01-makhrov-m-a/assets/113934714/7c242caf-e23e-41cc-8c20-b92ea410ceba)

- Паттерн strategy позволяет клиентскому коду (в данном случае классы Context) выбирать между различными алгоритмами сортировки (представленными BuubbleSort и QuickSort) во время выполнения,
не изменяя код клиента. 
- Это обеспечивает гибкость, поскольку вы можете переключаться между различными алгоритмами сортировки, не изменяя реализацию клиента.
- Это также способствует повторному использованию кода, поскольку вы можете добавлять новые алгоритмы сортировки (конкретные стратегии), реализуя интерфейс SortingStrategy без изменения существующего кода. 

## _Достоинства паттерна Strategy:_
- Систему проще поддерживать и модифицировать, так как семейство алгоритмов перенесено в отдельную иерархию классов. 
- Паттерн Strategy предоставляет возможность замены одного алгоритма другим в процессе выполнения программы 
- Паттерн Strategy позволяет скрыть детали реализации алгоритмов от клиента. 

## _Недостатки паттерна Strategy:_
- Для правильной настройки системы пользователь должен знать об особенностях всех алгоритмов. 
- Число классов в системе, построенной с применением паттерна Strategy, возрастает. 


## _Список литературы_
- https://www.modernescpp.com/index.php/the-strategy-pattern/
- https://digestcpp.com/designpattern/behavioral/strategy/
- https://www.geeksforgeeks.org/strategy-method-design-pattern-c-design-patterns/
- http://cpp-reference.ru/patterns/behavioral-patterns/strategy/

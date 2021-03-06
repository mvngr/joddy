# Joddy

Программа для отображения `.osm` формата. Есть возможность кастомизировать вид карты внутри программы

На данный момент приложение находится в стадии разработки. Степень ее готовности можно увидеть на скриншоте ниже

![Скриншот #9](https://i.imgur.com/Odc6v80.png) 
![Скриншот #7](https://i.imgur.com/vXKIKuf.png)
![Скриншот #8](https://i.imgur.com/tqCvQFd.png)

Скриншоты предыдущих версий:

[![Скриншот #6](https://i.imgur.com/9RO7W8Om.png)](https://i.imgur.com/9RO7W8O.png)
[![Скриншот #5](https://i.imgur.com/zzu2TONm.png)](https://i.imgur.com/zzu2TON.png)
[![Скриншот #4](https://i.imgur.com/oUQDtOQm.png)](https://i.imgur.com/oUQDtOQ.png)
[![Скриншот #3](https://imgur.com/ZiUPhWEm.png)](https://imgur.com/ZiUPhWE.png)
[![Скриншот #2](https://i.imgur.com/m8GHWk3m.png)](https://i.imgur.com/m8GHWk3.png)
[![Скриншот #1](https://i.imgur.com/UNqMjcYm.png?1)](https://i.imgur.com/UNqMjcY.png?1)

## Документация

### MainWindow

Класс, отвечающий за отрисовку интерфейса и его взаимодействие с пользователем

Переменная | Описание
----------------|----------------------
Ui::MainWindow &#42;ui | Указатель на `mainwindow.ui`
JoddyGraphicView &#42;map_ | Указатель на экземпляр класса `JoddyGraphicView`
JoddyController &#42;controller_ | Указатель на экземпляр класса `JoddyController`
OsmParser &#42;parser_ | Указатель на экземпляр класса `OsmParser`
statusBar &#42;progress_ | Указатель на надпись о статусе программы на панели `statusBar`

Тип | Метод | Параметры | Описание
--|-------|-----|----------------------
 &#45;| MainWindow | QWidget &#42;parent | Создает все необходимые для корректной работы программы экземпляры классов и передает их в `controller_`. Так же добавляет в `statusBar` `QLabel *progress_`
void | on_openFile_triggered | &#45; | Обработчик выпадающего меню "Открыть файл...". Вызывает окно выбора файла в системе с `.osm` форматом

### JoddyController

Класс для управления и синхронизации действий между другими классами. Является основой работы программы

Переменная | Описание
----------------|----------------------
NodeStorage &#42;nodeStorage_ | Указатель на экземпляр класса `NodeStorage`
JoddyGraphicView &#42;map_ | Указатель на экземпляр класса `JoddyGraphicView`
QList<Building &#42;> &#42;buildings_ | Массив объектов класса `Building`

Тип | Метод | Параметры | Описание
--|-------|-----|----------------------
 &#45; | JoddyController | &#45; | Инициализирует переменные
NodeStorage | &#42;getNodeStorage | &#45; | Возвращает ссылку на экземпляр класса `NodeStorage`
void | setMap | JoddyGraphicView &#42;map | Инициализирует экземпляр класса `JoddyGraphicView` и передает ему указатели на `nodeStorage_` и `buildings_` для дальнейшей корректной работы `map_`
void | setBuilding | Building &#42;b | Добавляет в массив `buildings_` ещё один элемент `b`, после чего вызывает метод класса `Building`  - `setPolygon`

### JoddyGraphicView

Класс для управления отрисовкой самой карты на сцене. В настоящий момент класс активно дорабатывается и приводится в порядок

Переменная | Описание
----------------|----------------------
QGraphicsScene &#42;scene | Указатель на экземпляр класса `NodeStorage`
QGraphicsItemGroup &#42;gPoints_ | Указатель на экземпляр класса `QGraphicsItemGroup`. Хранит в себе отрисованные `points_`
QTimer &#42;mapUpdate_ | Таймер для обновления карты
QList<QPointF> &#42;points_ | Массив из объектов `QPointF`
QList<Building &#42;> &#42;buildings_ | Массив из экземпляров класса `Building`

Тип | Метод | Параметры | Описание
--|-------|-----|----------------------
void | setsetPoints | QList<QPointF> &#42;list | Заполняет переменную `points_`
void | setBuildings | QList<Building &#42;> &#42;list | Заполняет переменную `buildings_`
void | resizeEvent | QResizeEvent &#42;event | Создан для корректной отрисовки карты при изменении размеров окна программы
void | deleteItemsFromGroup | QGraphicsItemGroup &#42;param | удаляет группу `param` из отрисовки

### OsmParser

Парсер `.osm` формата. При работе заполняет экземпляры классов данными из `.osm` файла

Переменная | Описание
----------------|----------------------
JoddyController &#42;controller_ | Указатель на экземпляр класса `JoddyController`
QFile &#42;file_ | Указатель на экземпляр класса `QFile`
QString path_ | Строка, хранящая ссылку на `.osm` файл

Тип | Метод | Параметры | Описание
--|-------|-----|----------------------
 &#45; | OsmParser | QString path, JoddyController &#42;controller | Инициализирует все необходимые переменные и проверяет корректность данных из `path`
bool | readFile | &#45; | Парсер документа. Считывает данные и на их основе дополняет созданные ранее классы новыми данными

### Object

Базовый класс для всех объектов на карте. Нельзя инициализировать, не унаследовав

Переменная | Описание
----------------|----------------------
QList<QPointF> points_ | Массив точек объекта 
QColor stroke_ | Цвет обводки
QColor fill_ | Цвет заливки
Materials material_ | Материал объекта, один из заранее перечисленных в `enum Materials`

Тип | Метод | Параметры | Описание
--|-------|-----|----------------------
&#45; | Object | &#45; | Инициализирует экземпляр класса по умолчанию
&#45; | Object | QList<QPointF> points, Materials material | Инициализирует из точек и материала
&#45; | Object | QList<QPointF> points, Materials material, QColor fill, Materials material | Инициализирует из точек и материала и цветов элемента
QList<QPointF> | getPoints | &#45; | Возвращает массив точек экземпляра класса
QColor | getStrokeColor | &#45; | Возвращает цвет обводки
QColor | getFillColor | &#45; | Возвращает цвет заливки
QPointF | getPoint | int index | Возвращает точку с индексом `index` от массива точек экземпляра класса
void | setPoints | QList<QPointF> points | Присваивает `points` массиву точек экземпляра класса
void | setStrokeColor | QColor color | Присваивает цвет обводки экземпляру класса
void | setFillColor | QColor color | Присваивает цвет заливки экземпляру класса
void | addPoint | QPointF point | Добавляет точку в существующий массив точек
void | addPoint | double x, double y | Добавляет точку, созданную из координат `x` и `y` в существующий массив точек

### NodeStorage

Класс, создаваемый для хранения и удобного доступа к точкам карты. Необходим для корректной работы `OsmParser` 

Переменная | Описание
----------------|----------------------
QList<QPointF> nodes_ | Массив точек объекта 
QMap<QString, int> association_ | Цвет обводки
double minLat_ | Минимальная широта
double minLon_ | Минимальная долгота
double corrLat_ | Максимальная широта
double corrLon_ | Максимальная долгота
bool isResized_ | Были ли координаты точек преобразованны и подогнаны под координаты для отображения на дисплее

Тип | Метод | Параметры | Описание
--|-------|-----|----------------------
&#45; | NodeStorage | &#45; | Инициализирует переменные, необходимые для корректной работы программы
void | setBounds | double minlat, double minlon, double maxlat, double maxlon | Фиксирует минимальные и максимальные длины и широты. Нужно для корректного отображения размеров карты
void | addNode | QString id, double lat, double lon | Добавляет `node` с карты и добавляет в массив ассоциаций номер точки `id` из `.osm` формата
QList<QPointF> &#42; | getNodes | &#45; | Возвращает весь массив точек (все точки `.osm` карты)
QPointF | getPoint | QString number | Возвращает точку, основываясь на массиве ассоциаций `association_`, который своим значением показывает индекс запрашиваемого элемента в массиве `nodes_`
void | resizePlace | &#45; | Преобразует координаты местности на карте в координаты экрана. Создает по заданным `minLon_`, `minLat_`, `maxLon_`, `maxLat_` квадрат для экрана со сторонами 1000x1000. Далее совершает изменение размера для каждой из точек массива для корректного отображения в этом квадрате. Пример преобразования точки: `53.23451` => `284.343255`. В этом преобразовании первое значение - долгота или широта на карте, а второе - x и y для экрана. Данные для экрана хранятся в переменных с плавающей точкой для того, чтобы можно было без сильных утрат местоположения увеличивать большие карты

### Описания классов Building, Way ожидайте в ближайшее время
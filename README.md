# Joddy

Программа для отображения `.osm` формата

На данный момент приложение находится в стадии разработки. Степень ее готовности можно увидеть на скриншоте ниже

![Скриншот #2](https://i.imgur.com/m8GHWk3.png)

Скриншоты предыдущих версий:

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

### Object, Building, NodeStorage

Ожидайте документацию на эти классы в ближайшее время...

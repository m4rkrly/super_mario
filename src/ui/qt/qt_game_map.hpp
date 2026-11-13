// Класс-QObject, оркестрирующий в себе QGraphicsScene и QGraphicsViewer
// Имеет пустой show()
// clear() реализуется с учётом того, что сцена НЕ ДОЛЖНА инициировать удаление
// QGraphicsItem'ов, а лишь вернуть владение ими
// Имеет get_viewer, который возвращает указатель на QGraphicsViewer для
// QtUIFactory

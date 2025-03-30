«Автономный автомобиль-робот с рулевым механизмом Аккермана, использующий лазерный дальномер, инерциальный модуль и энкодеры для самостоятельной навигации в ограниченном пространстве. Управление осуществляется посредством ROS.»

## 1. Перечень комплектующих (Аппаратная часть робота)

### 1. Микроконтроллер
- Arduino nano

### 2. Драйвер двигателей
- L298N H-bridge (2 шт.)

### 3. Энкодер
- FC-03 (2 шт.)

### 4. Бортовой компьютер
- Raspberry Pi 3 B+

### 5. Питание
- Li-lion аккумулятор 3.6V (4 шт.)
  
### 6. Мотор
- R130 motor

## 2.Схема подключения

## 3. IMU

Инерциальная навигационная система (INS, INS – Inertial Navigation System) использует информацию о вращении и ускорении от инерциального измерительного модуля (IMU – Inertial Measurement Unit) для вычисления относительного положения объекта с течением времени.

Счисление координат (англ. dead reckoning произошло от термина deduced reckoning, употребляющегося в  сфере мореплавания) – это простая математическая процедура, позволяющая оценить текущее местоположение транспортного средства путем оценки предыдущего положения с помощью известной информации о направлении и  скорости движения в течение заданного промежутка времени [39]. Подавляющее большинство существующих сегодня беспилотных систем полагается на метод счисления координат как на основную навигационную стратегию. Наиболее упрощенной реализацией этого метода является колесная одометрия  – оценка перемещения посредством данных, поступающих с колесных энкодеров. В этом разделе мы рассмотрим непосредственно сами энкодеры, причины погрешностей колесной одометрии и способы их минимизации.



### Рулевой механизм Аккермана

<!-- В качестве основного инструмента одометрии в проекте используется  -->

В качестве колесных энкодеров используется  принцип рулевого управления Аккермана, поскольку именно он преимущественно применяется в автомобильной промышленности. Данный рулевой механизм обеспечивает поворот внутреннего переднего колеса на немного более острый угол, чем внешнего, тем самым устраняя
проскальзывание шин, вызванное геометрическими особенностями. Система рулевого управления Аккермана представляет собой довольно точное решение для одометрии, поскольку в ней учитывается сила сцепления и дорожный просвет, которые важны для работы на любой местности. Таким образом, данная система лучше всего подходит для функционирования БТС в реальных условиях. Транспортные средства, использующие такую систему, как правило, оснащены бензиновым или дизельным двигателем, а также механической или автоматической коробкой передач, где мощность передается на четыре колеса через раздаточную коробку, дифференциал и карданные соединения.

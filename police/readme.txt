Ассоциативные контейнеры

к Ассоциативным контейнерам относятся:

map,set,multimap,multiset.

Все Ассоциативные контейнеры - хранят информацию в виде бинарного дерева.

map и set - это уникальные деревья к которым два раза нельзя добавить одно и то же значение.

multimap и multiset - являются не уникальными, то есть значения могут повторяться.

каждый элемент map хранит пару - "ключ-значение"    pair<key,value>
ключ и значение могут быть абсолютно разного типа.

тип ключа и тип значения обязательно создаются при создании объекта map.

все ключи в одном map уникальны, а значения могут повторяться.

в multimap ключи также могут повторяться.

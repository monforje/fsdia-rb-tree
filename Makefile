# Имя исполняемого файла
TARGET = list

# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Исходные файлы
SRC = list.cpp

# Правило сборки
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Правило для очистки скомпилированных файлов
clean:
	rm -f $(TARGET)

# Запуск программы
run: $(TARGET)
	./$(TARGET)

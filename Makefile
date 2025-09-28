# Nome do executável final
TARGET = vendingMachine

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Diretórios
SRC_DIR = src
BUILD_DIR = build

# Fontes e objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Regra principal
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilar cada .cpp em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Garantir que a pasta build existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Limpar objetos e binários
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

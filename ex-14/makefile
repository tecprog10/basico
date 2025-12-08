# Compilador
CXX := g++
CXXFLAGS := -std=c++20 -Wall -DSFML_STATIC

# Caminhos do SFML
SFML_INCLUDE := "C:/Program Files (x86)/SFML/include"
SFML_LIB := "C:/Program Files (x86)/SFML/lib"

# Diretórios do projeto
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
BIN_DIR := bin

# Arquivos
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TARGET := $(BIN_DIR)/app.exe

# Includes
INCLUDES := -I$(SFML_INCLUDE) -I$(INCLUDE_DIR)

# Bibliotecas (ORDEM IMPORTA! Dependências vêm depois)
LIBS := -L$(SFML_LIB) \
        -lsfml-graphics-s \
        -lsfml-window-s \
        -lsfml-network-s \
        -lsfml-system-s \
        -lfreetype \
        -lharfbuzz \
        -lz \
        -lopengl32 \
        -lwinmm \
        -lgdi32 \
        -lws2_32 \
        -lkernel32 \
        -luser32 \
        -lshell32 \
        -ladvapi32 \
        -lole32 \
        -loleaut32 \
        -limm32 \
        -lversion \
        -lsetupapi

# ============================================
# REGRAS
# ============================================

all: dirs $(TARGET)

dirs:
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

# Linkar (OBJETOS VÊM ANTES DAS LIBS!)
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LIBS) -static-libgcc -static-libstdc++

# Compilar
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)

run: $(TARGET)
	@$(TARGET)

rebuild: clean all

.PHONY: all clean run rebuild dirs
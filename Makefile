CC = g++
CFLAGS =-Iinclude -Llib -lxd -lglad -lglfw3 -lrt -lm -ldl -lX11 -lpthread 

BIN_DIR = bin
LIB_DIR = lib
BUILD_DIR = build
SRC_DIR = src

DEPS = $(subst $(LIB_DIR)/,$(BUILD_DIR)/,$(subst .cpp,.o,$(wildcard $(LIB_DIR)/*.cpp)))

FILES = $(wildcard $(SRC_DIR)/*.cpp)
OUT = $(subst $(SRC_DIR)/,$(BIN_DIR)/,$(FILES))
BINS = $(subst .cpp,,$(OUT))

all: folders $(BINS)
	@echo "Updated!"

run-%:
	./$(BIN_DIR)/$(subst run-,,$@)

$(BIN_DIR)/%: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $(DEPS) $(subst $(BIN_DIR)/,$(SRC_DIR)/,$@).cpp
	
build/%.o: $(LIB_DIR)/%.cpp
	@$(CC) -c $(CFLAGS) $< -o $@

folders:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

.PRECIOUS: $(BUILD_DIR)/%.o

testes:
	@echo $(DEPS)
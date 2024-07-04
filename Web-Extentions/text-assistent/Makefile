SRC_DIR := src
RELEASE_DIR := release
ZIP_FILE := $(RELEASE_DIR)/HireMate.zip

.PHONY: all clean

all: $(ZIP_FILE)

$(ZIP_FILE): $(SRC_DIR)
	@mkdir -p $(RELEASE_DIR)
	@zip -r $(ZIP_FILE) $(SRC_DIR)

clean:
	@rm -f $(ZIP_FILE)

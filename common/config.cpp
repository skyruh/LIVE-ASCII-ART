// Application configuration settings

struct AppConfig {
    // Window settings
    int window_width = 1280;
    int window_height = 720;
    bool fullscreen = false;
    const char* window_title = "ASCII Camera";

    // Camera settings
    int camera_id = 0;
    int camera_fps = 30;
    int camera_width = 640;
    int camera_height = 480;

    // Processing settings
    int downsample_factor = 8;
    bool enable_edge_detect = false;
    float edge_threshold = 0.5f;
    bool enable_grayscale = true;

    // ASCII rendering
    int ascii_width = 160;
    int ascii_height = 90;
    float brightness_threshold = 0.5f;
    const char* charset = " .:-=+*#%@";

    // UI settings
    bool show_fps = true;
    bool show_settings_panel = true;
    bool show_raw_feed = true;
    bool show_processed_feed = true;
    bool show_ascii_output = true;

    // Performance
    bool vsync_enabled = true;
    int max_queue_size = 5;
};


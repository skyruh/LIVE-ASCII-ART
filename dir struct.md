ascii-cam/
├── CMakeLists.txt                 # top-level build config
├── README.md
├── .gitignore
│
├── common/                        # SHARED CONTRACT — everyone agrees on this first, rarely touched after
│   ├── types.h                    # RawFrame, AsciiCell, AsciiGrid
│   └── config.h                   # AppConfig struct
│
├── external/                      # third-party libs (as submodules or vendored)
│   ├── glfw/
│   ├── imgui/
│   ├── opencv/                    # or linked via vcpkg instead of vendored
│   └── stb/                       # stb_image.h — used for B's standalone test images
│
├── assets/
│   ├── fonts/
│   │   └── mono_font.ttf          # monospace font atlas for ASCII rendering
│   └── test_images/               # static images Person B & C use before camera is wired in
│       └── sample1.jpg
│
├── src/
│   ├── main.cpp                   # thin entry point — calls into app/
│   │
│   ├── app/                       # PERSON A — window, camera, texture pipeline
│   │   ├── window.h / window.cpp
│   │   ├── camera_capture.h / camera_capture.cpp
│   │   ├── frame_queue.h / frame_queue.cpp   # thread-safe buffer
│   │   └── texture.h / texture.cpp
│   │
│   ├── processing/                # PERSON B — image processing
│   │   ├── grayscale.h / grayscale.cpp
│   │   ├── edge_detect.h / edge_detect.cpp
│   │   └── downsample.h / downsample.cpp
│   │
│   ├── ascii_render/               # PERSON C — ASCII mapping & rendering
│   │   ├── char_mapper.h / char_mapper.cpp
│   │   ├── grid_builder.h / grid_builder.cpp
│   │   └── font_atlas_render.h / font_atlas_render.cpp
│   │
│   └── ui/                        # PERSON D — settings panel & layout
│       ├── settings_panel.h / settings_panel.cpp
│       ├── feed_panels.h / feed_panels.cpp
│       └── fps_counter.h / fps_counter.cpp
│
├── tests/                         # each person can drop standalone test mains here
│   ├── test_processing_static.cpp     # B: run pipeline on assets/test_images/*, print/save result
│   ├── test_ascii_render_fake.cpp     # C: feed a fake brightness grid, view output
│   └── test_ui_dummy.cpp              # D: render panel with a dummy AppConfig, no camera needed
│
├── docs/
│   └── module_contracts.md        # the agreed function signatures — source of truth if a header changes
│
└── build/                         # gitignored, CMake output
if meson.project_name() != 'nnstreamer'

  project('capi-nnstreamer', 'c',
    version: '0.1',
    license: ['LGPL'],
    meson_version: '>=0.42.0',
    default_options: [
      'werror=true',
      'warning_level=1',
      'c_std=c89'
    ]
  )

  add_project_arguments('-DVERSION="'+meson.project_version()+'"', language: ['c', 'cpp'])

  cc = meson.get_compiler('c')
  cxx = meson.get_compiler('cpp')
endif


inc = include_directories('include')
nninc = include_directories('../../gst')
capi_inc = [inc, nninc]

capi_main = []
capi_main += join_paths(meson.current_source_dir(), 'src', 'nnstreamer-capi-pipeline.c')
capi_main += join_paths(meson.current_source_dir(), 'src', 'nnstreamer-capi-util.c')
capi_main += join_paths(meson.current_source_dir(), 'src', 'nnstreamer-capi-single.c')

if get_option('enable-tizen')
  capi_main += join_paths('src', 'nnstreamer-capi-tizen.c')
endif

capi_devel_main = []
capi_devel_main += join_paths(meson.current_source_dir(), 'include', 'nnstreamer.h')
capi_devel_main += join_paths(meson.current_source_dir(), 'include', 'nnstreamer-single.h')
if get_option('enable-tizen')
  # header for Tizen internal API
  capi_devel_main += join_paths(meson.current_source_dir(), 'include', 'nnstreamer-tizen-internal.h')
endif

# Dependencies
capi_deps = [
  nnstreamer_dep, glib_dep, gst_dep, gst_app_dep
]

if (get_option('enable-tizen'))
  message('CAPI is in Tizen mode')

  tizen_deps = [
    dependency('dpm'),
    dependency('mm-resource-manager'),
    dependency('mm-camcorder'),
    dependency('capi-privacy-privilege-manager'),
    dependency('capi-base-common'),
    dependency('capi-system-info'),
    dependency('dlog')
  ]

  capi_deps += tizen_deps
endif

shared_library ('capi-nnstreamer',
  capi_main,
  dependencies: capi_deps,
  include_directories: capi_inc,
  install: true,
  install_dir: nnstreamer_libdir,
)
nnstreamer_capi_lib = static_library ('capi-nnstreamer',
  capi_main,
  dependencies: capi_deps,
  include_directories: capi_inc,
  install: true,
  install_dir: nnstreamer_libdir,
)

nnstreamer_capi_dep = declare_dependency(link_with: nnstreamer_capi_lib,
  dependencies: capi_deps,
  include_directories: capi_inc,
)

# New single-shot c-api
capi_single_new_main = []
capi_single_new_main += join_paths(meson.current_source_dir(), 'src', 'nnstreamer-capi-pipeline.c')
capi_single_new_main += join_paths(meson.current_source_dir(), 'src', 'nnstreamer-capi-util.c')
capi_single_new_main += join_paths(meson.current_source_dir(), 'src', 'nnstreamer-capi-single-new.c')
capi_single_new_main += join_paths(meson.current_source_dir(), 'src', 'tensor_filter_single.c')

if get_option('enable-tizen')
  capi_single_new_main += join_paths('src', 'nnstreamer-capi-tizen.c')
endif

shared_library ('capi-nnstreamer-single-new',
  capi_single_new_main,
  dependencies: capi_deps,
  include_directories: capi_inc,
  install: true,
  install_dir: nnstreamer_libdir,
)
nnstreamer_capi_single_new_lib = static_library ('capi-nnstreamer-single-new',
  capi_single_new_main,
  dependencies: capi_deps,
  include_directories: capi_inc,
  install: true,
  install_dir: nnstreamer_libdir,
)

nnstreamer_capi_single_new_dep = declare_dependency(
  link_with: nnstreamer_capi_single_new_lib,
  dependencies: capi_deps,
  include_directories: capi_inc,
)

configure_file(input: 'capi-nnstreamer.pc.in', output: 'capi-nnstreamer.pc',
  install_dir: join_paths(nnstreamer_libdir, 'pkgconfig'),
  configuration: nnstreamer_conf
)

configure_file(input: 'capi-nnstreamer-single-new.pc.in', output: 'capi-nnstreamer-single-new.pc',
  install_dir: join_paths(nnstreamer_libdir, 'pkgconfig'),
  configuration: nnstreamer_conf
)

install_headers(capi_devel_main,
  subdir: 'nnstreamer'
)



class Context:
    def __init__(self):
        self.features_root_directories = []
        self.function_root_directory = ''
        self.features = []
        self.step_dir_done = []
        self.module_descriptions = []
        self.function_root_directories = []
        self.function_root_directory = ''
        self.function_files = []
        self.functions = []
        self.features_for_cpp = []
        self.functions_for_cpp = []
        self.hlr_file = ''
        self.traceability = False
        self.result_exception = []
        self.add_id_numbers = False
        self.remove_id_numbers = False
        self.add_traceability_tag = False
        self.remove_traceability_tag = False
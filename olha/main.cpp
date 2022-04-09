#include "SequenceGeneration.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


namespace py = pybind11;

PYBIND11_MODULE(sequence_generation, m) {
    m.doc() = R"pbdoc(
        sequence_generation
        -----------------------
        .. currentmodule:: sequence_generation
        .. autosummary::
    )pbdoc";

    py::class_<SequenceGenerationVDJ>(m, "SequenceGenerationVDJ")
        .def(py::init<const std::string &>(), "Create an object SequenceGenerationVDJ"
             " that can generate VDJ sequences")
        .def("generate", &SequenceGenerationVDJ::generate,
             "Generate a random nucleotide sequence" )
        .def("load_model", &SequenceGenerationVDJ::load_file,
             "Load the Olga model" )
        ;

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}

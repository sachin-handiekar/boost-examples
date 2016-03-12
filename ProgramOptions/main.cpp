#include <iostream>
#include <boost/program_options.hpp>

namespace opt = boost::program_options;

int main(int argc, char *argv[]) {
    opt::options_description desc("Boost Program Options Example");

    desc.add_options()
            ("name,n", opt::value<std::string>(), "Your Name")
            ("age,a", opt::value<int>(), "Your age")
            ("city,c", opt::value<std::string>(), "Your City")
            ("help", "Print the help messages.");


    if (argc < 2) {
        std::cout << desc << "\n";
        return -1;
    }

    opt::variables_map vm;

    opt::store(opt::parse_command_line(argc, argv, desc), vm);

    opt::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (vm.count("name")) {
        std::cout << "Name : " << vm["name"].as<std::string>() << "\n";
    }

    if (vm.count("age")) {
        std::cout << "Age : " << vm["age"].as<int>() << "\n";
    }

    if (vm.count("city")) {
        std::cout << "City : " << vm["city"].as<std::string>() << "\n";
    }

    return 0;
}
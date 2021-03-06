#include <iostream>

#include "argh.h"

int demo_easy(int argc, char const* argv[])
{
  std::cout << "::: Babytown Frolics! :::" << std::endl;

  bool help;
  int  mynumber;

  Argh argh;
  argh.addFlag(help, "--help");
  argh.addOption<int>(mynumber, 123, "--mynumber");
  argh.parse(argc, argv);

  if (help) {
    std::cout << argh.getUsage() << std::endl;
  }

  std::cout << "mynumber = " << mynumber << std::endl;
  std::cout << std::endl;

  return EXIT_SUCCESS;
}

int demo_medium(int argc, char const* argv[])
{
  std::cout << "::: I've been around the block! :::" << std::endl;

  bool                     help;
  bool                     boolValue;
  float                    floatValue;
  int                      intValue;
  std::string              stringValue;
  std::vector<float>       multiValue;
  std::vector<std::string> multiStringValue;

  Argh argh;
  argh.addFlag(help, "--help", "Display this message");
  argh.addOption<bool>(boolValue, false, "--boolvalue", "True? False?");
  argh.addOption<float>(floatValue, 3.14f, "--floatvalue", "Get real");
  argh.addOption<int>(intValue, 123, "--intvalue", "Optional description");
  argh.addOption<std::string>(stringValue, "It's a default", "--stringvalue");
  argh.addMultiOption<float>(multiValue, "1.f,2.f,3.f", "--multivalue", "See? Look up. Told you it was optional!");
  argh.addMultiOption<std::string>(multiStringValue, "one,two,three", "--multistringvalue", "It's so easy!");

  argh.load("argh.opts");
  argh.parse(argc, argv);

  std::cout << argh.getUsage() << std::endl;

  if (argh.isParsed("--multivalue")) {
    std::cout << "multiValue changed from the default to:" << std::endl;
    for (auto v : multiValue) {
      std::cout << v << std::endl;
    }
  }
  std::cout << std::endl;

  return EXIT_SUCCESS;
}

int demo_hard(int argc, char const* argv[])
{
  std::cout << "::: Futurejet fighter pilot! :::" << std::endl;

  Argh argh('|');
  std::vector<std::string> complex;
  argh.addMultiOption<std::string>(complex, "one|two", "--complex");
  argh.parse(argc, argv);

  std::cout << argh.getUsage() << std::endl;

  std::cout << "You so crazy. complex is:" << std::endl;
  for (auto c : complex) {
    std::cout << c << std::endl;
  }
  std::cout << std::endl;

  return EXIT_SUCCESS;
}

int main(int argc, char const* argv[])
{
  demo_easy(argc, argv);
  demo_medium(argc, argv);
  demo_hard(argc, argv);
  return EXIT_SUCCESS;
}
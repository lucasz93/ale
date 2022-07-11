#include "gtest/gtest.h"

#include "ale/Load.h"

#include "cspice_state.h"

#include <stdexcept>
#include <memory>

using namespace std;

TEST(PyInterfaceTest, LoadInvalidLabel) {
  std::shared_ptr<void> cspice(cspice_alloc(), &cspice_free);
  std::string label = "Not a Real Label";
  EXPECT_THROW(ale::load(cspice.get(), label), invalid_argument);
}


TEST(PyInterfaceTest, LoadValidLabel) {
  std::shared_ptr<void> cspice(cspice_alloc(), &cspice_free);
  std::string label = "../pytests/data/EN1072174528M/EN1072174528M_spiceinit.lbl";
  ale::load(cspice.get(), label, "", "isis");
}

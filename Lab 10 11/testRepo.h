#pragma once

#include "Repository.h"

class TestRepo {
public:
	TestRepo() {
		test_prob();
	};

private:

	void test_prob() {
		ProbabilityRepo repo(1); ///100% chance of succeeding
		Materie m{"POO", "Ana", 30};
		repo.add_materie(m);
		repo.delete_materie(0);
	}
};
//
// Created by lfnnx on 21.06.19.
//

#include "FunctionGenerator.h"

struct FunctionGenerator {

    Function * generateFunction(char probConst, char probUn, char probBin) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0,probBin + probConst + probUn-1);

        char rnd = dist(rng);
        if (rnd < probConst) {
            return generateConstFunction();
        } else if (rnd < probConst + probBin && rnd >= probConst) {
            return generateBinaryFunction();
        } else if (rnd >= probConst + probBin) {
            return generateUnaryFunction();
        }

    }

    BinaryFunction * generateBinaryFunction() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0,6);

        char rnd = dist6(rng);
        Function * fun1 = generateFunction(2, 2, 1);
        Function * fun2 = generateFunction(2, 2, 1);
        switch (rnd) {
            case 0:
                return new BinaryFunction(fun1, fun2, PLUS);
            case 1:
                return new BinaryFunction(fun1, fun2, MINUS);
            case 2:
                return new BinaryFunction(fun1, fun2, MUL);
            case 3:
                return new BinaryFunction(fun1, fun2, DIV);
            case 4:
                return new BinaryFunction(fun1, fun2, OR);
            case 5:
                return new BinaryFunction(fun1, fun2, AND);
            case 6:
                return new BinaryFunction(fun1, fun2, XOR);
            default:
                std::cout << "Fehler in FunctionGenerator::generateUnaryFunction()";
                exit(-1);
        }
    }

    UnaryFunction * generateUnaryFunction() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0,1);

        char rnd = dist(rng);
        switch (rnd) {
            case 0:
                return new UnaryFunction(generateFunction(2,2,1),NEGATE);
            case 1:
                return new UnaryFunction(generateFunction(2,2,1),COMPLEMENT);
            default:
                std::cout << "Fehler in FunctionGenerator::generateUnaryFunction()";
                exit(-1);
        }
    }

    static ConstFunction * generateConstFunction() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0,2);

        char rnd = dist(rng);
        switch (rnd) {
            case 0:
                return new ConstFunction(X);
            case 1:
                return new ConstFunction(Y);
            case 2:
                return new ConstFunction(Z);
            default:
                std::cout << "Fehler in FunctionGenerator::generateConstFunction()";
                exit(-1);
        }
    }
};
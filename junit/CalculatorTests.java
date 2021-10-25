import static org.junit.jupiter.api.Assertions.assertEquals;
import org.junit.jupiter.api.Test;

/**
 * Copied from https://junit.org/junit5/docs/current/user-guide/#writing-tests
 */
class CalculatorTests {

    private final Calculator calculator = new Calculator();

    @Test
    void addition() {
        // expected, actual, [optional failure string]
        assertEquals(6, calculator.add(1, 2, 3));
    }
}

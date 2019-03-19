## Architectural Patterns
The following are architectural patterns implemented by the SpiralBound system.

### Composite
The notebook heavily represents the composite architectural pattern. You start with a root node for the part-whole structure tree - the **Book** class. This book contains numerous **Section**s, and each section contains numerous **Page**s.

### Singleton
~~The **Book** class is representative of a singleton. Since a single notebook should only be open at one time, it makes sense that only one instance of the class should be available at any given time.~~ _(This architectural pattern was discarded due to issues with time cost regarding implementation.)_
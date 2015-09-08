<?hh // strict
namespace Decouple\Registry;
class Registry {
  public Map<mixed,mixed> $entries;
  public function __construct(KeyedTraversable<mixed,mixed> $entries) {
    $this->entries = new Map($entries);
  }
  /**
   * Set a registry value
   */
  public function set(mixed $key, mixed $value) : void {
    $this->entries->set($key, $value);
  }
  /**
   * Add a registry value (alias of set)
   */
  public function add(mixed $key, mixed $value) : void {
    $this->set($key, $value);
  }
  /**
   * Get a registry value
   */
  public function get(mixed $key, mixed $default=false) : mixed {
    if($this->entries->contains($key)) {
      return $this->entries->at($key);
    }
    return $default;
  }
  /**
   * Get the map of registry values
   */
  public function map() : Map<mixed,mixed> {
    return $this->entries;
  }
}

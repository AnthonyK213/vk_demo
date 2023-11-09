# Understanding Vulkan Objects

[Link](https://gpuopen.com/learn/understanding-vulkan-objects/)

- Each Vulkan objects is a value of a specific type with the prefix `Vk`

![Diagram](http://gpuopen.com/wp-content/uploads/2017/07/Vulkan-Diagram.png)

- **Instance**
  - Represents the connection from the app to the Vulkan runtime
  - Only should exist once in the app
  - Stores all app specific state required to use Vulkan
  - Must specify all layers and all extensions are needed when creating an instance

- **PysicalDevice**
  - Represents a specific Vulkan-compatible device (graphics card e.g.)
  - Can enumerate all available types of **Queue Families**
  - Can enumerate Memory Heaps and Memory Types inside them
    - **Memory Heap**
      - Represents a specific pool of RAM
        > May abstract the system RAM on the motherboard or certain memory space
        > in video RAM on a dedicated graphics card, or any other host- or device-
        > specific memory the implementation wants to expose
    - **Memory Type**
      - Must specify the Memory Type when allocating memory
      - Holds specific requirements for the memory blob (Binary Large Object)
        like visible to the host, coherent (between CPU and GPU) and cached

- **Device**
  - Logical device
  - Is the main object that represents an initialized Vulkan device that is ready
    to create all other objects
  - During device creation, you need to specify which features you want to enable,
    and some of them are fundamental like anisotropic(各向异性的) texture filtering
  - Must state all queues that will be use, their number and their Queue Families

- **Queue**
  - Represents a queue of commands to be executed on the device
  - All the actual work to be done by the GPU is requested by filling CommandBuffers
    and submitting them to Queues, using the function `vkQueueSubmit`

- **CommandPool**
  - Is used to allocate CommandBuffers.
  - It is connected to a specific Queue Family

- **CommandBuffer**
  - Is allocated from a specific CommandPool
  - Represents a buffer of various command to be executed by a logical device
  - Can call various functions on a command buffer, all of them starting with `vkCmd`
  - Used to specify the order, type and parameters of tasks that should be
    performed when the CommandBuffer is submitted to a Queue and is finally consumed
    by the device

- **Sampler**
  - Is **not** bound to any specific Image
  - It is rather just a set of state parameters (filtering mode or addressing mode, etc.)

> **Buffer** and **Image** are two types of resource that occupy device memory

- **Buffer**
  - Is a container for any binary data that just has its length, expressed in bytes

- **Image**
  - Represents a set of pixels
  - In other graphics APIs may call it *texture*

- **DeviceMemory**
  - Represents a block of memory allocated from a specific memory type with a specific
    length in bytes
  - Shouldn't allocate separate DeviceMemory for each Buffer or Image. Instead,
    should allocate bigger chunks of memory and assign parts of them to the Buffers
    and Images

- **SwapChainKHR**
  - Represents a set of images that can be presented on the Surface
  - These images already have their backing memory allocated by the system

- Views
  - **Buffer** and **Image** are not always used directly in rendering
  - Like view in database - sets of parameters that can be used to look at a set
    of underlying data in a desired way
  - **BufferView**
  - **ImageView**

- Descriptors
  - The way shaders can access these resources (Buffers, Images and Samplers)
  - Descriptors don't exist on their own, but are always grouped in descriptor sets
  - **DescriptorSetLayout**
    - Behaves like a template for a descriptor set
  - **DescriptorPool**
    - A simple object used to allocate descriptor sets
  - **DescritptorSet**
    - Represents memory that holds actual descriptors
    - Can be configured so that a descriptor points to specific Buffer, BufferView,
      Image or Sampler (`vkUpdateDescriptorSets`)

- **PipelineLayout**

- **RenderPass**

- **Pipeline**
  - **ShaderModule**
  - **PipelineCache**

- **Query**
  - **QueryPool**

- **Fence**

- **Semaphore**

- **Event**

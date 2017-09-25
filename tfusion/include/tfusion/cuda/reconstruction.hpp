#pragma once

namespace tfusion
{
	template<class TVoxel>
	class SceneReconstruction<TVoxel,VoxelBlockHash>
	{
	private:
		void *allocationTempData_device;
		void *allocationTempData_host;
		unsigned char *entriesAllocType_device;
		Vector4s *blockCoords_device;

	public:
		void ResetScene(Scene<TVoxel,VoxelBlockHash> *scene);

		void AllocateSceneFromDepth(Scene<TVoxel, VoxelBlockHash> *scene, const Intr intr, 
	const Matrix4f pose, cuda::Dist &dist,const RenderState *renderState,bool onlyUpdateVisibleList = false,bool resetVisibleList = false);

		void IntegrateIntoScene(Scene<TVoxel, VoxelBlockHash> *scene, const Intr intr,
	const Matrix4f pose, cuda::Dist& dist, const RenderState *renderState);

		SceneReconstruction(void);
		~SceneReconstruction(void);
	}
}